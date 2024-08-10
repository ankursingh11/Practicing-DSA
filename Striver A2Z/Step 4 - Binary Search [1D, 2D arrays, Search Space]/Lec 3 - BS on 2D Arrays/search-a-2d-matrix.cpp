
// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        if(numRows == 0) return false;
        int numCols = matrix[0].size();

        int low = 0, high = numRows*numCols-1;
        while(low <= high){
            int mid = (low + high)>>1;
            int row = mid/numCols;
            int col = mid%numCols;
            
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};