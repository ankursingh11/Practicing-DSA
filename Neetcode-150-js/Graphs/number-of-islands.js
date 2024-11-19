
// https://leetcode.com/problems/number-of-islands/

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    let numRows = grid.length;
    let ans = 0;
    if(numRows === 0) return ans;
    let numCols = grid[0].length;

    const visited = Array.from({length : numRows}, () => Array(numCols).fill(false));

    const dfs = (grid, x, y) => {
        if(x < 0 || x >= numRows || y < 0 || y >= numCols) return;

        visited[x][y] = true;
        const Dx = [-1, 0, 1, 0];
        const Dy = [0, 1, 0, -1];
        for(let i = 0; i < 4; i++){
            let newX = x + Dx[i];
            let newY = y + Dy[i];
            if((newX >= 0 && newX < numRows && newY >= 0 && newY < numCols) && !visited[newX][newY] && grid[newX][newY] === "1"){
                dfs(grid, newX, newY);
            }
        }
    }

    for(let i = 0; i < numRows; i++){
        for(let j = 0; j < numCols; j++){
            if(grid[i][j] === "1" && !visited[i][j]){
                dfs(grid, i, j)
                ans++;
            }
        }
    }

    return ans;
};