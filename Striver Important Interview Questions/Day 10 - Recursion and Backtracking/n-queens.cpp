
// https://leetcode.com/problems/n-queens/

class Solution {
public:

    bool canQueenPlaced(vector<string>&board, int row, int col, int n){
        int i, j;

        // vertical upward direction
        i = row-1;
        while(i >= 0){
            if(board[i][col] == 'Q') return false;
            i--;
        }

        // diagonal left direction
        i = row-1, j = col-1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        // diagonal right direction
        i = row-1, j = col+1;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void solve(int n, vector<vector<string>>&ans, vector<string>&board, int currRow){
        if(currRow == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(canQueenPlaced(board, currRow, col, n)){
                board[currRow][col] = 'Q';
                solve(n, ans, board, currRow+1);
                board[currRow][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) board[i] = s;

        int currRow = 0;
        solve(n, ans, board, currRow);

        return ans;
        
    }
};
