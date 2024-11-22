
// https://leetcode.com/problems/permutations/

class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>&ans, int n, int si){

        if(si == n){
            ans.push_back(nums);
            return;
        }

        for(int i = si; i < n; i++){
            swap(nums[i], nums[si]);
            solve(nums, ans, n, si+1);
            swap(nums[i], nums[si]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;

        solve(nums, ans, n, 0);
        return ans;
    }
};