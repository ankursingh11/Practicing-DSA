
// https://leetcode.com/problems/product-of-array-except-self/description/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> prod(size, 1);
        int temp = 1;
        
        for(int i = 0; i < size; i++){
            prod[i] = temp;
            temp = temp*nums[i];
        }

        temp = 1;
        for(int i = size-1; i >= 0; i--){
            prod[i] = prod[i]*temp;
            temp = temp*nums[i];
            nums[i] = prod[i];
        }

        return nums;
    }
};