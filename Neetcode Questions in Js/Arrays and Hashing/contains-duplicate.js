
// https://leetcode.com/problems/contains-duplicate/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    const st = new Set();
    for(let i = 0; i < nums.length; i++){
        if(st.has(nums[i])) return true;
        st.add(nums[i]);
    }
    return false;
};