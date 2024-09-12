
// https://leetcode.com/problems/longest-consecutive-sequence/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const visited = {};
    const indexes = {};
    let len = nums.length;
    for(let i = 0; i < len; i++){
        visited[nums[i]] = false;
        indexes[nums[i]] = i;
    }

    let lcs = 0;
    for(let i = 0; i < len; i++){
        let num = nums[i];
        let tempNum = num;
        let count = 0;

        // forward
        while(!visited[num] && indexes[num] !== undefined){
            visited[num] = true;
            count++;
            num++;
        }

        // backward
        num = tempNum-1;
        while(!visited[num] && indexes[num] !== undefined){
            visited[num] = true;
            count++;
            num--;
        }

        lcs = Math.max(lcs, count);
    }

    return lcs;
};