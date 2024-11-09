
// https://leetcode.com/problems/set-matrix-zeroes/

/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    let rowSize = matrix.length;
    let colSize = matrix[0].length;

    let rows = Array.from({length : rowSize}, () => 0);
    let cols = Array.from({length : colSize}, () => 0);
    
    for(let i = 0; i < rowSize; i++){
        for(let j = 0; j < colSize; j++){
            if(matrix[i][j] === 0){
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for(let i = 0; i < rowSize; i++){
        for(let j = 0; j < colSize; j++){
            if(rows[i] === 1 || cols[j] === 1){
                matrix[i][j] = 0;
            }
        }
    }
};