
#include<bits/stdc++.h>
using namespace std;

bool helper(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int dfs(vector<vector<int>>&grid, int n, int m, vector<vector<bool>>&visited, int x, int y){
    int ans = 1;
    visited[x][y] = true;
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        
        if(helper(newX, newY, n, m) && !visited[newX][newY] && grid[newX][newY] == 1){
            ans += dfs(grid, n, m, visited, newX, newY);
        }
    }
    
    return ans;
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    int ans = 0;
    int n = grid.size();
    if(n == 0) return ans;
    int m = grid[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == 1){
                ans = max(ans, dfs(grid, n, m, visited, i, j));
            }
        }
    }
    
    return ans;
}