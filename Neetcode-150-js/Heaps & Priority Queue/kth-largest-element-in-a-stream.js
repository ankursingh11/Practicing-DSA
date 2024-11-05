
// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class MinHeap {
    constructor() {
        this.heap = [];
    }

    getSize() {
        return this.heap.length;
    }

    peek() {
        return this.heap[0];
    }

    push(val) {
        this.heap.push(val);
        this.bubbleUp();
    }

    pop() {
        if (this.getSize() === 1) return this.heap.pop();
        
        const top = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        
        return top;
    }

    bubbleUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];
        
        while (index > 0) {
            let parentIndex = Math.floor((index - 1) / 2);
            let parent = this.heap[parentIndex];
            
            if (element >= parent) break;
            
            this.heap[index] = parent;
            index = parentIndex;
        }
        
        this.heap[index] = element;
    }

    bubbleDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[0];
        
        while (true) {
            let leftChildIndex = 2 * index + 1;
            let rightChildIndex = 2 * index + 2;
            let swap = null;
            
            if (leftChildIndex < length) {
                let leftChild = this.heap[leftChildIndex];
                if (leftChild < element) {
                    swap = leftChildIndex;
                }
            }
            
            if (rightChildIndex < length) {
                let rightChild = this.heap[rightChildIndex];
                if (
                    (swap === null && rightChild < element) ||
                    (swap !== null && rightChild < this.heap[swap])
                ) {
                    swap = rightChildIndex;
                }
            }
            
            if (swap === null) break;
            
            this.heap[index] = this.heap[swap];
            index = swap;
        }
        
        this.heap[index] = element;
    }
}

class KthLargest {
    constructor(k, nums) {
        this.k = k;
        this.minHeap = new MinHeap();
        
        for (let num of nums) {
            this.minHeap.push(num);
            if (this.minHeap.getSize() > k) {
                this.minHeap.pop();
            }
        }
    }

    add(val) {
        this.minHeap.push(val);
        if (this.minHeap.getSize() > this.k) {
            this.minHeap.pop();
        }
        return this.minHeap.peek();
    }
}

// Usage:
// const obj = new KthLargest(k, nums);
// const param_1 = obj.add(val);
