
// https://leetcode.com/problems/edit-distance/description/

class Solution {
public:

    int solve(string word1, string word2, vector<vector<int>>&dp){
        int m = word1.size();
        int n = word2.size();
        if(m == 0 || n == 0) return max(m, n);
        
        if(dp[m][n] != -1) return dp[m][n];
        if(word1[0] == word2[0]) return solve(word1.substr(1), word2.substr(1), dp);
        else{
            int deleteCost = 1 + solve(word1.substr(1), word2, dp);
            int insertCost = 1 + solve(word1, word2.substr(1), dp);
            int replaceCost = 1 + solve(word1.substr(1), word2.substr(1), dp);
            dp[m][n] = min({deleteCost, insertCost, replaceCost});
        }
        return dp[m][n];
    }

    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        if(m == 0 || n == 0) return max(m, n);
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(word1, word2, dp);
    }
};