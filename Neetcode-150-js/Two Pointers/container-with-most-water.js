
// https://leetcode.com/problems/container-with-most-water/description/

/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let len = height.length;
    let ans = 0;
    if(len === 0) return ans;

    let left = 0, right = len-1;
    while(left <= right){
        let smallAns = (right-left)*Math.min(height[left], height[right]);
        ans = Math.max(ans, smallAns);
        height[left] <= height[right] ? left++ : right--;
    }
    return ans;
};