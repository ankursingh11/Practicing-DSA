
// https://leetcode.com/problems/subsets/

class Solution {
public:

    void subsets(vector<int>&nums, vector<vector<int>>&ans, int startingIndex, vector<int>&subset){
        ans.push_back(subset);
        for(int i = startingIndex; i < nums.size(); i++){
            subset.push_back(nums[i]);
            subsets(nums, ans, i+1, subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        int startingIndex = 0;
        vector<int> subset;
        subsets(nums, ans, startingIndex, subset);
        return ans;
    }
};