
// https://leetcode.com/problems/maximum-product-subarray/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
    const n = nums.length;
    let ans = Number.MIN_SAFE_INTEGER;
    if(n === 0) return ans;

    let p1 = 1, p2 = 1;
    for(let i = 0; i < n; i++){
        let j = n-i-1;
        p1 = nums[i]*p1;
        p2 = nums[j]*p2;
        ans = Math.max(ans, p1, p2);
        // console.log(ans);
        if(p1 === 0) p1 = 1;
        if(p2 === 0) p2 = 1;
    }

    return ans;
};