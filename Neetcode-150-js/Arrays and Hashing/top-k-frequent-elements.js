
// https://leetcode.com/problems/top-k-frequent-elements/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
  const obj = {};
  for(const num of nums){
    if(obj[num]){
      obj[num].count++;
    }else obj[num] = {'num' : num, 'count' : 1};
  }
  
  // console.log(obj);
  const topK = Array.from(Object.values(obj))
  .sort((a, b) => b.count - a.count)
  .splice(0, k)
  .map(ele => ele.num);
  
  // console.log(topK);
  return topK;
};