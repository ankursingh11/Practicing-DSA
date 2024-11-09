
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let len = nums.length;

    let start = 0, end = len-1;
    while(start <= end){
        let mid = Math.floor((start+end)/2);

        if(nums[mid] === target) return mid;
        
        if(nums[start] <= nums[mid]){
            if(nums[start] <= target && target <= nums[mid]){
                end = mid-1;
            }else start = mid+1;
        }else{
            if(nums[mid] <= target && target <= nums[end]){
                start = mid+1;
            }else end = mid-1;
        }
    }

    return -1;
};