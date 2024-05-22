
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        if(grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        int ans = 0, count = 0, tot = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] != 0) tot++;
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            int n = q.size();
            count += n;
            for(int i = 0; i < n; i++){
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                for(int j = 0; j < 4; j++){
                    int newX = x + dx[j];
                    int newY = y + dy[j];

                    if(newX < 0 || newX >= row || newY < 0 || newY >= col || grid[newX][newY] != 1) continue;
                    q.push({newX, newY});
                    grid[newX][newY] = 2;
                }
            }

            if(!q.empty()) ans++;
        }

        return (count == tot) ? ans : -1;
    }
};