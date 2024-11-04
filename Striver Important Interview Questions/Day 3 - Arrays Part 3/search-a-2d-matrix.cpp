
// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLen = matrix.size();
        if(rowLen == 0) return false;
        int colLen = matrix[0].size();

        int start = 0, end = rowLen*colLen-1;
        while(start <= end){
            int mid = (start + end)/2;
            int currRow = mid/colLen;
            int currCol = mid%colLen;
            
            if(matrix[currRow][currCol] == target) return true;
            else if(matrix[currRow][currCol] < target) start = mid+1;
            else end = mid-1;
        }

        return false;
    }
};