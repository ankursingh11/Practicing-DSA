
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:

    bool checkValidPoints(int x, int y, int numRows, int numCols){
        return (x >= 0 && x < numRows && y >= 0 && y < numCols);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int minutes = 0;
        int numRows = grid.size();
        if(numRows == 0) return minutes;
        int numCols = grid[0].size();

        queue<pair<int, int>> q;
        int expectedRottenOranges = 0; 
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(grid[i][j] != 0) expectedRottenOranges++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int oranges = 0;
        while(!q.empty()){
            int n = q.size();
            oranges += n;
            for(int i = 0; i < n; i++){
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                for(int j = 0; j < 4; j++){
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if(checkValidPoints(newX, newY, numRows, numCols) && grid[newX][newY] == 1){
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                    }
                }
            }
            if(!q.empty()) minutes++;
        }

        return (oranges == expectedRottenOranges) ? minutes : -1;
    }
};