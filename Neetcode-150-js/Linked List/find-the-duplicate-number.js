
// https://leetcode.com/problems/find-the-duplicate-number/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let slow = nums[0];
    slow = nums[slow];

    let fast = nums[0];
    fast = nums[nums[fast]];

    while(slow !== fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = nums[0];
    while(slow !== fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
};