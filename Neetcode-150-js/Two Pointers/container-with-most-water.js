
// https://leetcode.com/problems/container-with-most-water/description/

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let ans = 0;
    let len = height.length;
    if(len === 0) return ans;

    let i = 0, j = len-1;
    while(i < j){
        let smallAns = (j-i)*Math.min(height[i], height[j]);
        ans = Math.max(ans, smallAns);
        (height[i] <= height[j]) ? i++ : j--;
    }
    return ans;
};