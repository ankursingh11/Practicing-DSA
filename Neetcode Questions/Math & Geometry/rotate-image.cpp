
// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rowSize = matrix.size();
        if(rowSize == 0) return;

        // transpose the matrix
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse each row
        for(int i = 0; i < rowSize; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        return;
    }
};