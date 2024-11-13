
// https://leetcode.com/problems/permutations/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
  let ans = [];
  let len = nums.length;
  if(len === 0) return ans;

  var solve = (si) => {

    if(si === len){
        ans = [...ans, [...nums]];
    }

    for(let i = si; i < len; i++){
        [nums[i], nums[si]] = [nums[si], nums[i]];
        solve(si+1);
        [nums[i], nums[si]] = [nums[si], nums[i]];
    }
  } 

  solve(0);
  return ans; 
};