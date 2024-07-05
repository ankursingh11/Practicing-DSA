
// https://leetcode.com/problems/word-search/description/

class Solution {
public:

    bool check(int x, int y, int rowSize, int colSize){
        return (x >= 0 && x < rowSize && y >= 0 && y < colSize);
    }


    bool dfs(vector<vector<char>>&board, string word, int rowSize, int colSize, vector<vector<bool>>&visited, int index, int x, int y){

        if(index == word.size()) return true;

        visited[x][y] = true;
        bool wordFound = false;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(check(newX, newY, rowSize, colSize) && !visited[newX][newY] && board[newX][newY] == word[index]){
                wordFound = wordFound | dfs(board, word, rowSize, colSize, visited, index+1, newX, newY);
            }
        }

        visited[x][y] = false;
        return wordFound;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int rowSize = board.size();
        if(rowSize == 0) return false;
        int colSize = board[0].size();

        vector<vector<bool>> visited(rowSize, vector<bool>(colSize, false));
        int index = 0;
        bool wordFound = false;
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                if(board[i][j] == word[0]){
                    wordFound = dfs(board, word, rowSize, colSize, visited, index+1, i, j);
                    if(wordFound) break;
                }
            }
            if(wordFound) break;
        }

        return wordFound;
    }
};