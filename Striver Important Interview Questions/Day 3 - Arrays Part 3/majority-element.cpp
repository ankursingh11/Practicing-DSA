
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return INT_MIN;
        
        int majorityElement = nums[0];
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] == majorityElement) count++;
            else count--;

            if(count == 0){
                count = 1;
                majorityElement = nums[i];
            }
        }

        return majorityElement;
    }
};