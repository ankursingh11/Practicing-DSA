
// https://www.geeksforgeeks.org/problems/coin-change2448/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
  public:
    long long int count(int coins[], int n, int sum) {

        // code here.
        vector<vector<long long int>> dp(n+1, vector<long long int>(sum+1, 0));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(coins[i-1] <= j) dp[i][j] = (long long int)dp[i][j-coins[i-1]] + (long long int)dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
};
