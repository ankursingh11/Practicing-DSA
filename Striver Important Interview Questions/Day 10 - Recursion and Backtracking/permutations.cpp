
// https://leetcode.com/problems/permutations/

class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>&ans, int startingIndex, int n){

        if(startingIndex == n){
            ans.push_back(nums);
        }

        for(int i = startingIndex; i < n; i++){
            swap(nums[i], nums[startingIndex]);
            solve(nums, ans, startingIndex+1, n);
            swap(nums[i], nums[startingIndex]);   
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        if(n == 0) return ans;

        int startingIndex = 0;
        solve(nums, ans, startingIndex, n);

        return ans;
    }
};