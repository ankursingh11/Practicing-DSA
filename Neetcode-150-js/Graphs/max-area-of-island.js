
// https://leetcode.com/problems/max-area-of-island/description/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
    let numRows = grid.length;
    let ans = 0;
    if(numRows === 0) return ans;
    let numCols = grid[0].length;

    const visited = Array.from({length : numRows}, () => Array(numCols).fill(false));

    const dfs = (x, y) => {
        let area = 1;
        visited[x][y] = true;
        const Dx = [-1, 0, 1, 0];
        const Dy = [0, 1, 0, -1];
        for(let i = 0; i < 4; i++){
            let newX = x + Dx[i];
            let newY = y + Dy[i];
            if((newX >= 0 && newX < numRows && newY >= 0 && newY < numCols) && !visited[newX][newY] && grid[newX][newY] === 1){
                area += dfs(newX, newY);
            }
        }
        return area;
    }

    for(let i = 0; i < numRows; i++){
        for(let j = 0; j < numCols; j++){
            if(!visited[i][j] && grid[i][j] === 1){
                let currentArea = dfs(i, j);
                ans = Math.max(ans, currentArea);
            }
        }
    }

    return ans;
};