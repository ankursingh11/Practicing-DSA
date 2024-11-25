
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto ele : nums){
            pq.push(ele);
        }

        int ans;
        while(k--){
            ans = pq.top();
            pq.pop();
        }

        return ans;
    }
};