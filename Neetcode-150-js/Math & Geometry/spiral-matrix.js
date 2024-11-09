
// https://leetcode.com/problems/spiral-matrix/description/

var spiralOrder = function(matrix) {

    const ans = [];

    let rowSize = matrix.length;
    if(rowSize === 0) return ans;
    let colSize = matrix[0].length;
    
    let totalElements = rowSize*colSize-1;
    let startingRow = 0;
    let endingRow = rowSize-1;
    let startingCol = 0;
    let endingCol = colSize-1;
    let k = 0;

    while(k <= totalElements){
        for(let i = startingCol; i <= endingCol && k <= totalElements; i++){
            ans.push(matrix[startingRow][i]);
            k++;
        }
        startingRow++;

        for(let i = startingRow; i <= endingRow && k <= totalElements; i++){
            ans.push(matrix[i][endingCol]);
            k++;
        }
        endingCol--;

        for(let i = endingCol; i >= startingCol && k <= totalElements; i--){
            ans.push(matrix[endingRow][i]);
            k++;
        }
        endingRow--;

        for(let i = endingRow; i >= startingRow && k <= totalElements; i--){
            ans.push(matrix[i][startingCol]);
            k++;
        }
        startingCol++;
    }

    return ans;
};