
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let len = nums.length;

    let start = 0, end = len-1;
    let minEle = Number.MAX_SAFE_INTEGER;
    while(start <= end){
        let mid = Math.floor((start+end)/2);
        
        if(nums[start] <= nums[mid]){
            minEle = Math.min(minEle, nums[start]);
            start = mid+1;
        }
        // nums[mid] <= nums[end]
        else{
            minEle = Math.min(minEle, nums[mid]);
            end = mid-1;
        }
    }

    return minEle;
};