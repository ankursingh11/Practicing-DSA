
// https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = {};
    for(let i = 0; i < nums.length; i++){
        if(map[target - nums[i]] >= 0){
            return [i, map[target-nums[i]]];
        }
        map[nums[i]] = i;
    }
    return [];
};