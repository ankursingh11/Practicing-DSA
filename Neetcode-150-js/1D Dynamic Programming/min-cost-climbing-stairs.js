
// https://leetcode.com/problems/min-cost-climbing-stairs/description/

/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    let n = cost.length;
    if(n === 0 || n === 1) return 0;

    const dp = Array.from({length : n+1}, () => -1);

    const solve = (i) => {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = cost[i] + Math.min(solve(i + 1), solve(i + 2)); // Compute minimum cost
        return dp[i];
    }

    return Math.min(solve(0), solve(1));
};