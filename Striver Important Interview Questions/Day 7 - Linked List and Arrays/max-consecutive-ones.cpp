
// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int size = nums.size();
        if(size == 0) return maxCount;

        int currCount = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == 1) currCount++;
            else{
                maxCount = max(maxCount, currCount);
                currCount = 0;
            }
        }
        maxCount = max(maxCount, currCount);
        return maxCount;
    }
};