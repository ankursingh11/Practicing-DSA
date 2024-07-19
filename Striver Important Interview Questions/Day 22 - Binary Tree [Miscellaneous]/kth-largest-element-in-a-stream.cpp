
// https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto num : nums) pq.push(num);

        while(pq.size() > K) pq.pop();
    }
    
    int add(int val) {
        if(pq.size() < K) pq.push(val);
        else if(val >= pq.top()){
            pq.push(val);
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */