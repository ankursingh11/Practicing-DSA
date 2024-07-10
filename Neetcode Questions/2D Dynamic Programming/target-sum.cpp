
// https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > abs(sum)) return 0;
        if(sum < target || (sum+target)%2!= 0) return 0;
        int n = nums.size();
        int targetSum = (target + sum)/2;

        vector<vector<int>> dp(n+1, vector<int>(targetSum+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        // dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= targetSum; j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
            }
        }

        return dp[n][targetSum];
    }
};