
// https://leetcode.com/problems/rotate-array/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    let len = nums.length;
    k = k%len;
    let rotated = [...nums.slice(len-k), ...nums.slice(0, len-k)];
    for(let i = 0; i < len; i++){
        nums[i] = rotated[i];
    }
};