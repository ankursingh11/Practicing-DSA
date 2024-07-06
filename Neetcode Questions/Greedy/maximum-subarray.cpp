
// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 0) return -1;
        int currSum = 0, maxSum = INT_MIN;
        for(auto num : nums){
            currSum += num;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }

        return maxSum;
    }
};