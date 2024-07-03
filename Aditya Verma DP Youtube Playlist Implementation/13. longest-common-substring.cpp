
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        // your code here
        
        if(m == 0 || n == 0) return 0;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }else dp[i][j] = 0;
            }
        }
        
        return ans;
    }
};
