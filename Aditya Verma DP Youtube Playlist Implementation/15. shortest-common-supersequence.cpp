
// https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        if(m == 0 || n == 0) return 0;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(X[i-1] == Y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        return (m+n-dp[m][n]);
    }
};
