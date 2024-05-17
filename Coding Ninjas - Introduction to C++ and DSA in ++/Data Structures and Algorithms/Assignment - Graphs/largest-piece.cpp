

#include<bits/stdc++.h>

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool validCoordinate(int x, int y, int rows, int cols){
  return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int dfs(vector<vector<int>>&cake, int n, vector<vector<bool>>&visited, int x, int y){
    
    if(visited[x][y]) return 0;
    visited[x][y] = true;
    int currentCakeSize = 1;
    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];

        if(validCoordinate(newX, newY, n, n) && !visited[newX][newY] && cake[newX][newY] == 1){
            currentCakeSize = currentCakeSize + dfs(cake, n, visited, newX, newY);
        }
    }

    return currentCakeSize;
}


int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int maxCakeSize = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){    
            if(!visited[i][j] && cake[i][j] == 1){
                maxCakeSize = max(maxCakeSize, dfs(cake, n, visited, i, j));
            }
        }
    }


    return maxCakeSize;
}