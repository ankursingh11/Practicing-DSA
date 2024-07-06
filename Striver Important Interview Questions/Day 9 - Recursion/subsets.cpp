
// https://leetcode.com/problems/subsets/

class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&subset, int startingIndex){
        ans.push_back(subset);

        for(int i = startingIndex; i < nums.size(); i++){
            subset.push_back(nums[i]);
            solve(nums, ans, subset, i+1);
            subset.pop_back();
        }

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;

        vector<int> subset;
        int startingIndex = 0;
        solve(nums, ans, subset, startingIndex);

        return ans;
    }
};