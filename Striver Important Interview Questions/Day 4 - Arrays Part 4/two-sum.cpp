
// https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.count(target - nums[i]) > 0){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};