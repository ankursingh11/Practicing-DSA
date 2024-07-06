
// https://leetcode.com/problems/combination-sum/

class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&subset, int n){

        if(n == 0){
            if(target == 0) ans.push_back(subset);
            return;
        }

        if(candidates[n-1] <= target){
            subset.push_back(candidates[n-1]);
            solve(candidates, target-candidates[n-1], ans, subset, n);
            subset.pop_back();
        }

        solve(candidates, target, ans, subset, n-1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        if(n == 0) return ans;

        vector<int> subset;
        solve(candidates, target, ans, subset, n);

        return ans;
    }
};