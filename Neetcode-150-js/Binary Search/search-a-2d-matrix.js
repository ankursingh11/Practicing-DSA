
// https://leetcode.com/problems/search-a-2d-matrix/description/

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let rowSize = matrix.length;
    if(rowSize === 0) return false;
    let colSize = matrix[0].length;
    
    let start = 0, end = rowSize*colSize-1;
    while(start <= end){
        let mid = Math.floor((start+end)/2);
        let row = Math.floor(mid/colSize);
        let col = mid%colSize;

        if(matrix[row][col] === target) return true;
        else if(matrix[row][col] < target) start = mid+1;
        else end = mid-1;
    }

    return false;
};