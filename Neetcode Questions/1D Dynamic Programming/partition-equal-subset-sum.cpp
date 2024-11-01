
// https://leetcode.com/problems/partition-equal-subset-sum/description/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return true;
    
        int numsSum = accumulate(nums.begin(), nums.end(), 0);
        if(numsSum%2 != 0) return false;
        int target = numsSum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
        }

        return dp[n][target];
    }
};