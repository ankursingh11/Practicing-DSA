

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool validCoordinate(int x, int y, int rows, int cols){
  return (x >= 0 && x < rows && y >= 0 && y < cols);
}

bool dfs(vector<vector<char>>&board, int rows, int cols, int x, int y, vector<vector<bool>>&visited, string str, int index){

  if(index == 11) return true;

  visited[x][y] = true;
  bool found = false;
  for(int i = 0; i < 8; i++){
    int newX = x + dx[i];
    int newY = y + dy[i];

    if(validCoordinate(newX, newY, rows, cols) && !visited[newX][newY] && board[newX][newY] == str[index]){
      found = found || dfs(board, rows, cols, newX, newY, visited, str, index+1);
    }
  }
  visited[x][y] = false;
  return found;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    int rows = n, cols = m;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    string str = "CODINGNINJA";

    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        if(!visited[i][j] && board[i][j] == str[0]){
          if(dfs(board, rows, cols, i, j, visited, str, 1)){
            return true;
          }
        }
      }
    }
    return false;
}