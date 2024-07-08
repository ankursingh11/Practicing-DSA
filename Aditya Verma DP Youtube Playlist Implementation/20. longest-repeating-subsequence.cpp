
// https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    int size = str.size();
		    if(size == 0) return 0;
		    
		    vector<vector<int>> dp(size+1, vector<int>(size+1, 0));
		    string X, Y;
		    X = Y = str;
		    
		    for(int i = 1; i <= size; i++){
		        for(int j = 1; j <= size; j++){
		            if(X[i-1] == Y[j-1] && i != j){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    
		    return dp[size][size];
		}

};