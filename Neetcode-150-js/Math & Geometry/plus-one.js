
// https://leetcode.com/problems/plus-one/description/

/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let carry = 1;
    let len = digits.length;
    let i = len-1;
    const ans = Array.from({length : len}, () => 0);
    while(i >= 0){
        let sum = digits[i] + carry;
        ans[i] = sum%10;
        carry = Math.floor(sum/10);
        i--;
    }
    if(carry > 0) ans.unshift(carry);
    return ans;
};