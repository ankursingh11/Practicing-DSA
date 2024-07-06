
// https://leetcode.com/problems/surrounded-regions/

class Solution {
public:

    bool isEdgePoint(int x, int y, int numRows, int numCols){
        return (x == 0 || x == numRows-1 || y == 0 || y == numCols-1);
    }

    bool isValidPoint(int x, int y, int numRows, int numCols){
        return (x >= 0 && x < numRows && y >= 0 && y < numCols);
    }

    void capture(vector<vector<char>>&board, int numRows, int numCols, int x, int y){
        if(!isValidPoint(x, y, numRows, numCols) || board[x][y] != 'O') return;

        board[x][y] = 'T';

        capture(board, numRows, numCols, x+1, y);
        capture(board, numRows, numCols, x-1, y);
        capture(board, numRows, numCols, x, y+1);
        capture(board, numRows, numCols, x, y-1);
        return;
    }

    void solve(vector<vector<char>>& board) {
        
        int numRows = board.size();
        if(numRows == 0) return;
        int numCols = board[0].size();

        // mark the regions which can not be surrounded(board edges containing 'O')
        // by 'T'
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(board[i][j] == 'O' && isEdgePoint(i, j, numRows, numCols)){
                    capture(board, numRows, numCols, i, j);
                }
            }
        }

        // mark all the remaining 'O' by 'X'
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        // mark all the 'T' with 'O'
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(board[i][j] == 'T') board[i][j] = 'O';
            }
        }

        return;
    }
};