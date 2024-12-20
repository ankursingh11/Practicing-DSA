
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
                if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                }else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][W];
        
    }
};
