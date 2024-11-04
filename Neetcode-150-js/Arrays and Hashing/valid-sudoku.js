
// https://leetcode.com/problems/valid-sudoku/description/

/**
 * @param {character[][]} board
 * @return {boolean}
 */

const LEN = 9;

var isValidSudoku = function(board) {
    
    const rowSet = Array.from({length : LEN}, () => new Set());
    const colSet = Array.from({length : LEN}, () => new Set());
    const boxSet = Array.from({length : LEN}, () => new Set());

    for(let i = 0; i < LEN; i++){
        for(let j = 0; j < LEN; j++){
            let val = board[i][j];
            if(val === ".") continue;
            let boxNumber = 3*Math.floor(i/3) + Math.floor(j/3);

            if(rowSet[i].has(val) || colSet[j].has(val) || boxSet[boxNumber].has(val)) return false;

            rowSet[i].add(val);
            colSet[j].add(val);
            boxSet[boxNumber].add(val);
        }
    }

    return true;
};