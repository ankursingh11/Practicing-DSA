
// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = INT_MIN, currSum = 0;
        for(auto ele : nums){
            currSum += ele;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }

        return maxSum;
    }
};