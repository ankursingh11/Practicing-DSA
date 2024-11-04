
// https://leetcode.com/problems/product-of-array-except-self/description/

/**
 * @param {number[]} nums
 * @return {number[]}
 */

var productExceptSelf = function(nums) {
    
    const len = nums.length;
    const prod = Array.from({length : len}, () => 1);
    let temp = 1;
    
    for(let i = 0; i < len; i++){
      prod[i] = temp;
      temp = temp*nums[i];
    }
    
    temp = 1;
    for(let i = len-1; i >= 0; i--){
      prod[i] = prod[i]*temp;
      temp = temp*nums[i];
      nums[i] = prod[i];
    }
    
    return nums;
};
