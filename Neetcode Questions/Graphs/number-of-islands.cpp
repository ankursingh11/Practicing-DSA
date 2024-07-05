
// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:

    bool validPath(int x, int y, int rows, int cols){
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    void dfs(vector<vector<char>>&grid, int rows, int cols, int x, int y, vector<vector<bool>>&visited){

        visited[x][y] = true;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(validPath(newX, newY, rows, cols) && !visited[newX][newY] && grid[newX][newY] == '1'){
                dfs(grid, rows, cols, newX, newY, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int numIslands = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, rows, cols, i, j, visited);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};