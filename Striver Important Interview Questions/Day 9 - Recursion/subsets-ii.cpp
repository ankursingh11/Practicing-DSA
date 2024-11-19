
// https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&subset, int si){
        ans.push_back(subset);

        for(int i = si; i < nums.size(); i++){
            if(i != si && nums[i] == nums[i-1]) continue;

            subset.push_back(nums[i]);
            solve(nums, ans, subset, i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<vector<int>> ans;
       if(nums.size() == 0) return ans;

       vector<int> subset;
       sort(nums.begin(), nums.end());
       solve(nums, ans, subset, 0);
       return ans; 
    }
};