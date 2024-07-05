
// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&subset, int startingIndex, int n){

        if(target == 0){
            ans.push_back(subset);
            return;
        }

        for(int i = startingIndex; i < n; i++){
            if(i != startingIndex && candidates[i] == candidates[i-1]) continue;
            if(target < candidates[i]) continue;
            subset.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, subset, i+1, n);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        int n = candidates.size();
        if(n == 0) return ans;

        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        int startingIndex = 0;
        solve(candidates, target, ans, subset, startingIndex, n);

        return ans;
    }
};