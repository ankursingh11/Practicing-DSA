
// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution{
		
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    
	    int m = str1.size(), n = str2.size();
	    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
	    
	    for(int i = 1; i <= m; i++){
	        for(int j = 1; j <= n; j++){
	            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
	            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    
	    int lcs = dp[m][n];
	    int deletions = m-lcs;
	    int insertions = n-lcs;
	    return (deletions + insertions);
	} 
};
