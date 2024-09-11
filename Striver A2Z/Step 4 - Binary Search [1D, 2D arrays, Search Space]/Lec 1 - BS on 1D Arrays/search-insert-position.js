
// https://leetcode.com/problems/search-insert-position/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let len = nums.length;
    let insertIndex = len;

    let start = 0, end = len-1;
    while(start <= end){
        let mid = Math.floor((start + end)/2);
        if(nums[mid] >= target){
            insertIndex = mid;
            end = mid-1;
        }else start = mid+1;
    }

    return insertIndex;
};