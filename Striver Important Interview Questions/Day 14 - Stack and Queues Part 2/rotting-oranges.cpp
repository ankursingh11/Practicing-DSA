
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:

    bool checkValid(int x, int y, int xLimit, int yLimit){
        return (x >= 0 && x < xLimit && y >= 0 && y < yLimit);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        
        int nRows = grid.size();
        if(nRows == 0) return 0;
        int nCols = grid[0].size();

        int total = 0, count = 0, time = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] != 0) total++;
            }
        }

        while(!q.empty()){
            int n = q.size();
            count += n;
            vector<pair<int, int>> arr;
            while(n--){
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;

                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, 1, 0, -1};
                for(int i = 0; i < 4; i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];

                    if(checkValid(newX, newY, nRows, nCols) && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        arr.push_back({newX, newY});
                    }
                }
            }
            for(auto ele : arr) q.push(ele);
            if(!q.empty()) time++;
        }

        return (total == count) ? time : -1;
    }
};