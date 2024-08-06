
// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int mRows = matrix.size();
        if(mRows == 0) return;
        int nCols = matrix[0].size();

        vector<int> row(mRows), col(nCols);
        for(int i = 0; i < mRows; i++){
            for(int j = 0; j < nCols; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < mRows; i++){
            for(int j = 0; j < nCols; j++){
                if(row[i] || col[j]) matrix[i][j] = 0;
            }
        }
        return;
    }
};