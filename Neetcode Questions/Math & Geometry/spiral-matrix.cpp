
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int r = matrix.size();
        if(r == 0) return ans;
        int c = matrix[0].size();

        int total = r*c;
        int count = 0;
        int startingRow = 0, endingRow = r-1;
        int startingCol = 0, endingCol = c-1;

        while(count < total){
            for(int i = startingCol; i <= endingCol && count < total; i++, count++) ans.push_back(matrix[startingRow][i]);
            startingRow++;
            for(int i = startingRow; i <= endingRow && count < total; i++, count++) ans.push_back(matrix[i][endingCol]);
            endingCol--;
            for(int i = endingCol; i >= startingCol && count < total; i--, count++) ans.push_back(matrix[endingRow][i]);
            endingRow--;
            for(int i = endingRow; i >= startingRow && count < total; i--, count++) ans.push_back(matrix[i][startingCol]);
            startingCol++;
        }

        return ans;
    }
};