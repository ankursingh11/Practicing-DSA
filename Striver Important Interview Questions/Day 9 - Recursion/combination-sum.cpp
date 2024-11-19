
// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&smallAns, int i){

        if(target == 0){
            ans.push_back(smallAns);
            return;
        }
        if(i >= candidates.size()) return;

        if(candidates[i] <= target){
            smallAns.push_back(candidates[i]);
            solve(candidates, target - candidates[i], ans, smallAns, i);
            smallAns.pop_back();
        }
        solve(candidates, target, ans, smallAns, i+1);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;

        vector<int> smallAns;
        solve(candidates, target, ans, smallAns, 0);
        return ans;
    }
};