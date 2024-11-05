
// https://leetcode.com/problems/3sum/description/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    const ans = [];
    let len = nums.length;
    if(len === 0) return ans;

    nums = nums.sort((a, b) => a-b);

    for(let i = 0; i < nums.length; i++){
        let start = i+1;
        let end = len-1;
        while(start < end){
            let currSum = nums[i] + nums[start] + nums[end];
            if(currSum === 0){
                const smallAns = [nums[i], nums[start], nums[end]];
                ans.push(smallAns);
                
                // removing duplicate element
                while(start < end && nums[start] === smallAns[1]) start++;
                while(start < end && nums[end] === smallAns[2]) end--;
                
            }else if(currSum < 0) start++;
            else end--;
        }
      
        while(i+1 < len && nums[i+1] === nums[i]) i++;
    }
    return ans; 
};