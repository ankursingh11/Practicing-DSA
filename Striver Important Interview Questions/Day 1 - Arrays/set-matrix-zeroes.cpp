
// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();

        vector<int> rows(rowLen, 0);
        vector<int> cols(colLen, 0);

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(rows[i] == 1 || cols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};