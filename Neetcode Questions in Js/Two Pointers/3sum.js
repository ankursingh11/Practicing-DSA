
// https://leetcode.com/problems/3sum/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    const ans = [];
    let len = nums.length;
    if(len === 0) return ans;
    
    // sort array in increasing order
    nums = nums.sort((a, b) => a-b);

    for(let i = 0; i < len; i++){
        let start = i+1;
        let end = len-1;
        while(start < end){
            let currSum = nums[i] + nums[start] + nums[end];

            if(currSum === 0){
                const smallAns = [nums[i], nums[start], nums[end]];
                ans.push(smallAns);
                while(start < end && smallAns[1] === nums[start]) start++;
                while(start < end && smallAns[2] === nums[end]) end--;
            }else if (currSum < 0) start++;
            else end--;
        }
        while(i+1 < len && nums[i] === nums[i+1]) i++;
    }
    return ans;
};