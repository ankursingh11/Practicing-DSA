
// https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < rowLen; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};