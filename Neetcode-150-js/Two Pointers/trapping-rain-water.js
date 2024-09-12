
// https://leetcode.com/problems/trapping-rain-water/description/

/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let capacity = 0;
    let len = height.length;
    if(len === 0) return capacity;

    let left = 0, right = len-1;
    let leftMax = 0, rightMax = 0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= leftMax) leftMax = height[left];
            else capacity += (leftMax - height[left]);
            left++;
        }else{
            if(height[right] >= rightMax) rightMax = height[right];
            else capacity += (rightMax - height[right]);
            right--;
        }
    }
    return capacity;
};