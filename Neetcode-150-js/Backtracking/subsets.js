
// https://leetcode.com/problems/subsets/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let ans = [];
    let len = nums.length;
    if(len === 0) return ans;
    
    const subset = [];

    var solve = (si) => {
        ans = [...ans, [...subset]];

        for(let i = si; i < len; i++){
            subset.push(nums[i]);
            solve(i+1);
            subset.pop();
        }
    }

    let si = 0;
    solve(si);
    return ans;
};