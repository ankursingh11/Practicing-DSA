
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();
        if(size == 0) return ans;

        unordered_map<int, int> mp;
        for(int i = 0; i < size; i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {i, mp[target - nums[i]]};
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};