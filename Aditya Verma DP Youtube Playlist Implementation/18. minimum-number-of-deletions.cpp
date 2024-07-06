
// https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

int lcs(string a, string b){
      int m = a.size();
      int n = b.size();
      
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      
      for(int i = 1; i <= m; i++){
          for(int j = 1; j <= n; j++){
              if(a[m-i] == b[n-j]) dp[i][j] = 1 + dp[i-1][j-1];
              else dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
          }
      }
      
      return dp[m][n];
  }


int minDeletions(string str, int n) { 
    //complete the function here 
    if(str.size() == 0) return 0;
    string str2 = str;
    reverse(str2.begin(), str2.end());
    
    return str.size() - lcs(str, str2);
}
