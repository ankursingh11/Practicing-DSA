
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:

    int solve(int index, int shouldBuy, vector<int>&prices, vector<vector<int>>&dp){
        if(index >= prices.size()) return 0;
        if(dp[index][shouldBuy] != -1) return dp[index][shouldBuy];

        if(shouldBuy){
            return dp[index][shouldBuy] = max(-prices[index] + solve(index+1, 0, prices, dp), 0+solve(index+1, 1, prices, dp));
        }else{
            return dp[index][shouldBuy] = max(prices[index] + solve(index+2, 1, prices, dp), 0+solve(index+1, 0, prices, dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        int shouldBuy = 1;
        return solve(0, shouldBuy, prices, dp);
    }
};