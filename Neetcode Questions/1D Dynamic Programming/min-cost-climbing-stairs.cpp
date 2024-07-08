
// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:

    int solve(vector<int>&cost, int n, int i, vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans += cost[i];
        dp[i] = ans;
        return dp[i] = ans + min(solve(cost, n, i+1, dp), solve(cost, n, i+2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0 || n == 1) return 0;
        vector<int> dp(n+1, -1);
        return min(solve(cost, n, 0, dp), solve(cost, n, 1, dp));
    }
};