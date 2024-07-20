
// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:

    bool validPoints(int x, int y, int numRows, int numCols){
        return ( x >= 0 && x < numRows && y >= 0 && y < numCols);
    }

    void dfs(vector<vector<char>>&grid, int numRows, int numCols, vector<vector<bool>>&visited, int x, int y){

        visited[x][y] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){

            int newX = x + dx[i];
            int newY = y + dy[i];

            if(validPoints(newX, newY, numRows, numCols) && !visited[newX][newY] && grid[newX][newY] == '1'){
                dfs(grid, numRows, numCols, visited, newX, newY);
            }
        }

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int numIslands = 0;
        int numRows = grid.size();
        if(numRows == 0) return numIslands;
        int numCols = grid[0].size();

        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
        
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, numRows, numCols, visited, i, j);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};