
// https://leetcode.com/problems/combination-sum/

/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let ans = [];
    let len = candidates.length;
    if(len === 0) return ans;

    let subset = [];

    var solve = (target, n) => {

        if(target === 0){
            ans = [...ans, [...subset]];
            return;
        }
        
        if(n === 0 || target < 0) return;

        if(candidates[n-1] <= target){
            subset.push(candidates[n-1]);
            solve(target - candidates[n-1], n);
            subset.pop();
        }
        solve(target, n-1);
    }

    solve(target, len);
    return ans;
};