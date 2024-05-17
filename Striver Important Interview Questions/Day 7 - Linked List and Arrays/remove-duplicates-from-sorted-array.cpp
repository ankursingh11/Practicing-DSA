
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int size = nums.size();
        if(size == 0) return j;

        for( ; i < size; i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }

        return (1+j);

    }
};