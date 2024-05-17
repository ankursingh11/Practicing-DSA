
// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ansIndex = -1;
        int size = nums.size();
        if(size == 0) return ansIndex;

        int rSum = accumulate(nums.begin(), nums.end(), 0);
        int lSum = 0;
        for(int i = 0; i < size; i++){
            rSum = rSum - nums[i];
            if(rSum == lSum){
                ansIndex = i;
                return ansIndex;
            }
            lSum = lSum + nums[i];
        }

        return ansIndex;
    }
};