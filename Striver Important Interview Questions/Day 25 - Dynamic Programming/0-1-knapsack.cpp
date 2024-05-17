
// https://www.naukri.com/code360/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            if(weights[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
        }
    }

    return dp[n][w];
}
