
// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countZero, countOne, countTwo;
        countZero = countOne = countTwo = 0;
        int size = nums.size();
        if(size == 0) return;

        for(auto ele : nums){
            if(ele == 0) countZero++;
            if(ele == 1) countOne++;
        }
        countTwo = size - (countZero + countOne);

        int i = 0;
        while(countZero--) nums[i++] = 0;
        while(countOne--) nums[i++] = 1;
        while(countTwo--) nums[i++] = 2;

        return;
    }
};