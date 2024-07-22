
// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:

    bool isValid(int x, int y, int xLimit, int yLimit){
        return (x >= 0 && x < xLimit && y >= 0 && y < yLimit);
    }

    int solve(vector<vector<int>>&grid, int numRows, int numCols, int i, int j, vector<vector<int>>&dp){
        if(i == numRows-1 && j == numCols-1) return grid[i][j];

        if(!isValid(i, j, numRows, numCols)) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = grid[i][j] + min(solve(grid, numRows, numCols, i+1, j, dp), solve(grid, numRows, numCols, i, j+1, dp));
    }


    int minPathSum(vector<vector<int>>& grid) {
        int numRows = grid.size();
        if(numRows == 0) return 0;
        int numCols = grid[0].size();

        vector<vector<int>> dp(numRows, vector<int>(numCols, -1));

        return solve(grid, numRows, numCols, 0, 0, dp);
    }
};