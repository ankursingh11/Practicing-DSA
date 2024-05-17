
// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nRows = matrix.size();
        int mCols = matrix[0].size();

        vector<int> zeroRows(nRows, -1);
        vector<int> zeroCols(mCols, -1);

        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < mCols; j++){
                if(matrix[i][j] == 0){
                    zeroRows[i] = 1;
                    zeroCols[j] = 1;
                }
            }
        }

        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < mCols; j++){
                if(zeroRows[i] == 1 || zeroCols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};