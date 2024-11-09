
// https://leetcode.com/problems/rotate-image/

/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let len = matrix.length;
    if(len === 0) return;

    for(let i = 0; i < len; i++){
        for(let j = 0; j < i; j++){
            [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
        }
    }

    for(let i = 0; i < len; i++){
        matrix[i].reverse();
    }

    return;
};