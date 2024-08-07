
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0) return ans;
        int n = matrix[0].size();

        int startRow = 0;
        int startCol = 0;
        int endRow = m-1;
        int endCol = n-1;
        int totalCount = m*n;
        int count = 0;
        while(count < totalCount){
            for(int i = startCol; i <= endCol && count < totalCount; i++, count++){
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;

            for(int i = startRow; i <= endRow && count < totalCount; i++, count++){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;

            for(int i = endCol; i >= startCol && count < totalCount; i--, count++){
                ans.push_back(matrix[endRow][i]);
            }
            endRow--;

            for(int i = endRow; i >= startRow && count < totalCount; i--, count++){
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
        return ans;
    }
};