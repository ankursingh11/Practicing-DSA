
// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        if(rows == 0) return;
        int cols = matrix[0].size();
        vector<int> rowSet(rows), colSet(cols);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    rowSet[i] = 1;
                    colSet[j] = 1;
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rowSet[i] == 1 || colSet[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};