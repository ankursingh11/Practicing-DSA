
// https://leetcode.com/problems/pacific-atlantic-water-flow/description/

class Solution {
public:

    bool checkValidPoints(int x, int y, int numRows, int numCols){
        return (x >= 0 && x < numRows && y >= 0 && y < numCols);
    }

    void dfs(vector<vector<int>>& heights, int numRows, int numCols, vector<vector<bool>>&visited, int x, int y){
        visited[x][y] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(checkValidPoints(newX, newY, numRows, numCols) && !visited[newX][newY] && heights[x][y] <= heights[newX][newY]){
                dfs(heights, numRows, numCols, visited, newX, newY);
            }   
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        int numRows = heights.size();
        if(numRows == 0) return ans;
        int numCols = heights[0].size();

        vector<vector<bool>> pacific(numRows, vector<bool>(numCols, false));
        vector<vector<bool>> atlantic(numRows, vector<bool>(numCols, false));

        // filling first and last rows
        for(int j = 0; j < numCols; j++){
            dfs(heights, numRows, numCols, pacific, 0, j); // first row
            dfs(heights, numRows, numCols, atlantic, numRows-1, j); // last row
        }

        // filling first and last cols
        for(int i = 0; i < numRows; i++){
            dfs(heights, numRows, numCols, pacific, i, 0); // first col
            dfs(heights, numRows, numCols, atlantic, i, numCols-1); // last col
        }

        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};