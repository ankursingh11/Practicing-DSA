

int visited[51][51];
int findCycle = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(char board[][MAXN], int x, int y, int fromX, int fromY, char color, int m, int n){
    if(x < 0 || x >= n || y < 0 ||y >=m) return;
    if(board[x][y]!=color) return;
    if(visited[x][y]){
        findCycle = 1;
        return;
    }
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX == fromX && newY == fromY) continue;
        dfs(board, newX, newY, x, y, color, m, n);
    }
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]) dfs(board, i, j, -1, -1, board[i][j], m, n);
        }
    }
    
    return findCycle;
}