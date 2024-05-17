
// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;

        int count1 = 0, count2 = 0, num1 = 0, num2 = 0;
        for(auto ele : nums){
            if(ele == num1) count1++;
            else if(ele == num2) count2++;
            else if(count1 == 0){
                num1 = ele;
                count1 = 1;
            }else if(count2 == 0){
                num2 = ele;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(auto ele : nums){
            if(ele == num1) count1++;
            else if(ele == num2) count2++;
        }

        int n = nums.size()/3;
        if(count1 > n) ans.push_back(num1);
        if(count2 > n) ans.push_back(num2);
        return ans;
    }
};