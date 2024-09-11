
// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return;

        int i = 0, j = 0;
        while(i < len){
            if(nums[i] != 0){
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};