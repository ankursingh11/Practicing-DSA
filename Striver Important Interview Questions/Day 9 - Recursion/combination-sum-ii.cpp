
// https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:

    void solve(vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&smallAns, 0){
        
        if(target == 0){
            ans.push_back(smallAns);
            return;
        }

        for(int i = si; i < candidates.size(); i++){
            if(i != si && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) return;
            smallAns.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, smallAns, i+1);
            smallAns.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;

        vector<int> smallAns;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ans, smallAns, 0);
        return ans;
    }
};