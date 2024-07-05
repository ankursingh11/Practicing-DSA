
// https://leetcode.com/problems/max-area-of-island/

class Solution {
public:

    bool helper(int x, int y, int m, int n){
        return (x < m && x >= 0 && y < n && y >= 0);
    }

    int solve(vector<vector<int>>&grid, int m, int n, vector<vector<bool>>&visited, int x, int y){
        int ans = 1;
        visited[x][y] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(helper(newX, newY, m, n) && !visited[newX][newY] && grid[newX][newY] == 1){
                ans += solve(grid, m, n, visited, newX, newY);
            }
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        if(m == 0) return ans;
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    int smallAns = solve(grid, m, n, visited, i, j);
                    ans = max(ans, smallAns);
                }
            }
        }

        return ans;
    }
};