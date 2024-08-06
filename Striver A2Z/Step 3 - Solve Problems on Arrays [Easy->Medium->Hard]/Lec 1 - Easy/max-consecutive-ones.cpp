
// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveCount = 0;
        int n = nums.size();
        if(n == 0) return maxConsecutiveCount;
        int currCount = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) currCount++;
            if(nums[i] != 1){
                maxConsecutiveCount = max(maxConsecutiveCount, currCount);
                currCount = 0;
            }
        }
        maxConsecutiveCount = max(maxConsecutiveCount, currCount);
        return maxConsecutiveCount;
    }
};