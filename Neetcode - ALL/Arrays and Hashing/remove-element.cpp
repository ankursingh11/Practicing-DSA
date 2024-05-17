
// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int size = nums.size();
        if(size == 0) return k;

        for(int i = 0; i < size; i++){
            if(nums[i] != val){
                swap(nums[i], nums[k]);
                k++;
            }
        }

        return k;
    }
};