
// https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<int> rowSet[n], colSet[n], boxSet[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                auto val = board[i][j];
                if(val == '.') continue;

                int boxNumber = 3*(i/3) + (j/3);

                if(rowSet[i].find(val) != rowSet[i].end()) return false;
                if(colSet[j].find(val) != colSet[j].end()) return false;
                if(boxSet[boxNumber].find(val) != boxSet[boxNumber].end()) return false;

                rowSet[i].insert(val);
                colSet[j].insert(val);
                boxSet[boxNumber].insert(val);
            }
        }

        return true;   
    }
};