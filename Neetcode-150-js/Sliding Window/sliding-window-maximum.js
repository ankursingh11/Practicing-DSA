
// https://leetcode.com/problems/sliding-window-maximum/description/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */

Array.prototype.back = function(){
    return this[this.length-1];
}

Array.prototype.empty = function(){
    return this.length === 0;
}

var maxSlidingWindow = function(nums, k) {
    let len = nums.length;
    const ans = [];

    // base case
    if(k > len || len === 0) return ans;
    if(k === len){
        ans.push(Math.max(...nums));
        return ans;
    }

    const window = [];
    for(let i = 0; i < k; i++){
        while(!window.empty() && nums[i] >= nums[window.back()]) window.pop();
        window.push(i);
    }

    ans.push(nums[window[0]]);

    for(let i = k; i < len; i++){
       while(!window.empty() && nums[i] >= nums[window.back()]) window.pop();
       while(!window.empty() && window[0] <= i-k) window.shift();
       window.push(i);
       ans.push(nums[window[0]]);         
    }

    return ans;
};