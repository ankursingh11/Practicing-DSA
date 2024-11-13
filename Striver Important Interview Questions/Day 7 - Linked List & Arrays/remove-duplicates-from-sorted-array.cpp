
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, i = 0;
        int len = nums.size();
        while(i < len){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
            i++;
        }
        return (j+1);
    }

};