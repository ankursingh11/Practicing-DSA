
// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = INT_MIN;
        int majority2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;

        for(auto num : nums){
            if(num == majority1) count1++;
            else if(num == majority2) count2++;
            else if(count1 == 0){
                majority1 = num;
                count1 = 1;
            }else if(count2 == 0){
                majority2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(auto num : nums){
            if(num == majority1) count1++;
            else if(num == majority2) count2++;
        }

        vector<int> ans;
        int n = nums.size();
        if(count1 > n/3) ans.push_back(majority1);
        if(count2 > n/3) ans.push_back(majority2);
        return ans;
    }
};