
// https://leetcode.com/problems/last-stone-weight/description/

class MaxHeap {
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
        
        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown();
        
        return max;
    }

    bubbleUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];
        
        while (index > 0) {
            let parentIndex = Math.floor((index - 1) / 2);
            let parent = this.heap[parentIndex];
            
            if (element <= parent) break;
            
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
                if (leftChild > element) {
                    swap = leftChildIndex;
                }
            }
            
            if (rightChildIndex < length) {
                let rightChild = this.heap[rightChildIndex];
                if (
                    (swap === null && rightChild > element) ||
                    (swap !== null && rightChild > this.heap[swap])
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

class Solution {
    lastStoneWeight(stones) {
        const maxHeap = new MaxHeap();
        
        for (let stone of stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.getSize() > 1) {
            let y = maxHeap.pop();
            let x = maxHeap.pop();

            if (y > x) {
                maxHeap.push(y - x);
            }
        }

        return maxHeap.getSize() === 0 ? 0 : maxHeap.peek();
    }
}

// Usage
// const solution = new Solution();
// const result = solution.lastStoneWeight([2,7,4,1,8,1]);
// console.log(result);
