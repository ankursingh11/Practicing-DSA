
// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        for(auto ele : nums){
            if(ele == 0) count0++;
            else if(ele == 1) count1++;
            else count2++;
        }
        
        int i = 0;
        for(int j = 0; j < count0; j++) nums[i++] = 0;
        for(int j = 0; j < count1; j++) nums[i++] = 1;
        for(int j = 0; j < count2; j++) nums[i++] = 2;
        return;
    }
};