
// https://leetcode.com/problems/lru-cache/description/

class Node {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {
    constructor(capacity) {
        this.size = capacity;
        this.head = new Node(-1, -1);
        this.tail = new Node(-1, -1);
        this.head.next = this.tail;
        this.tail.prev = this.head;
        this.map = new Map(); // Use JavaScript Map to store key-node pairs
    }

    deleteNode(node) {
        const { prev, next } = node;
        prev.next = next;
        next.prev = prev;
    }

    addNode(newNode) {
        const temp = this.head.next;
        this.head.next = newNode;
        newNode.next = temp;
        temp.prev = newNode;
        newNode.prev = this.head;
    }

    get(key) {
        if (this.map.has(key)) {
            const node = this.map.get(key);
            this.map.delete(key);
            this.deleteNode(node);
            this.addNode(node);
            this.map.set(key, this.head.next);
            return node.value;
        }
        return -1;
    }

    put(key, value) {
        if (this.map.has(key)) {
            const node = this.map.get(key);
            this.map.delete(key);
            this.deleteNode(node);
        }

        if (this.map.size === this.size) {
            const leastRecentNode = this.tail.prev;
            this.map.delete(leastRecentNode.key);
            this.deleteNode(leastRecentNode);
        }

        const newNode = new Node(key, value);
        this.addNode(newNode);
        this.map.set(key, this.head.next);
    }
}

/**
 * Example usage:
 * const obj = new LRUCache(capacity);
 * const param_1 = obj.get(key);
 * obj.put(key, value);
 */
