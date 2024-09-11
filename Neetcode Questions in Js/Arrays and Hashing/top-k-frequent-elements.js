
// https://leetcode.com/problems/top-k-frequent-elements/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const freq = {};
    nums.forEach((num) => {
        if(freq[num]) freq[num].count++;
        else freq[num] = {num, count : 1}
    })
    let temp = [];
    for(const key in freq) temp.push(freq[key]);
    temp = temp.sort((a, b) => a.count - b.count);
    // console.log(temp);
    const result = [];
    while(k--){
        result.push(temp.pop().num)
    }
    return result;
};