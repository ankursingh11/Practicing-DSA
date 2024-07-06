
// https://neetcode.io/problems/islands-and-treasure

class Solution {
public:

    bool checkValidPoints(int newX, int newY, int numRows, int numCols){
        return (newX >= 0 && newX < numRows && newY >= 0 && newY < numCols);
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int numRows = grid.size();
        if(numRows == 0) return;
        int numCols = grid[0].size();

        // finding treasure chests
        queue<pair<int, int>> q;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first, y = front.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(checkValidPoints(newX, newY, numRows, numCols) && grid[newX][newY] == INT_MAX){
                    grid[newX][newY] = grid[x][y]+1;
                    q.push({newX, newY});
                }
            }
        }

        return;
        
    }
};
