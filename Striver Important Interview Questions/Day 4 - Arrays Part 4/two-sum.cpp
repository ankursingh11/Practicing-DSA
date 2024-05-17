
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int size = nums.size();
        vector<int> ans;
        if(size == 0) return ans;

        unordered_map<int, int> mp;
        for(int i = 0; i < size; i++){
            if(mp.find(target - nums[i]) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                return ans;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};