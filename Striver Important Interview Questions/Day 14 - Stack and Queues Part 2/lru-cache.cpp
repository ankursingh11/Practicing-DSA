
// https://leetcode.com/problems/lru-cache/

class Node{
    public:
    int key;
    int value;
    Node*next;
    Node*prev;
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
    int size;
    Node*head = new Node(-1, -1);
    Node*tail = new Node(-1, -1);
    unordered_map<int, Node*> mp;

public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;    
    }

    void deleteNode(Node*node){
        Node*delNext = node->next;
        Node*delPrev = node->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addNode(Node*newNode){
        Node*temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head; 
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node*temp = mp[key];
            mp.erase(temp->key);
            deleteNode(temp);
            addNode(temp);
            mp[key] = head->next;
            return temp->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node*temp = mp[key];
            mp.erase(key);
            deleteNode(temp);
        }

        if(mp.size() == size){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */