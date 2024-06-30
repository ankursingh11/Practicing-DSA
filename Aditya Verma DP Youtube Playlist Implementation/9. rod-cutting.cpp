
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        
        vector<int> length(n);
        for(int i = 0; i < n; i++) length[i] = i+1;
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(length[i-1] <= j){
                    dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
                }else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][n];
    }
};
