
// https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityElement = 0;
        int size = nums.size();
        if(size == 0) return majorityElement;

        int countOfMajorityElement = 1;
        majorityElement = nums[0];

        for(int i = 1; i < size; i++){
            if(nums[i] == majorityElement) countOfMajorityElement++;
            else countOfMajorityElement--;
            if(countOfMajorityElement == 0){
                majorityElement = nums[i];
                countOfMajorityElement = 1;
            }
        }

        return majorityElement;
    }
};