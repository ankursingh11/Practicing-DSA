
// https://leetcode.com/problems/subsets-ii/

class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&subset, int startingIndex, int n){

        ans.push_back(subset);

        for(int i = startingIndex; i < n; i++){
            if(i != startingIndex && nums[i] == nums[i-1]) continue;

            subset.push_back(nums[i]);
            solve(nums, ans, subset, i+1, n);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;

        sort(nums.begin(), nums.end());
        vector<int> subset;
        int startingIndex = 0;
        solve(nums, ans, subset, startingIndex, n);

        return ans;
    }
};