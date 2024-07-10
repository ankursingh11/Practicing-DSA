
// https://leetcode.com/problems/unique-paths/

class Solution {
public:

    int solve(int m, int n, int x, int y, vector<vector<int>>&dp){
        if(x < 0 || x >= m || y < 0 || y >= n) return 0;
        if(x == m-1 && y == n-1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = solve(m, n, x+1, y, dp) + solve(m, n, x, y+1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0, dp);
    }
};