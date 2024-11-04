
// https://leetcode.com/problems/longest-consecutive-sequence/

var longestConsecutive = function(nums) {
    const len = nums.length;
    const visited = {};
    const indexes = {};

    for(let i = 0; i < nums.length; i++){
        visited[nums[i]] = false;
        indexes[nums[i]] = i;
    }
    
    let maxLength = 0;
    for(let i = 0; i < len; i++){
      let currentLength = 0;
      let temp = nums[i];
      let tempNum = temp;
      
      // forward propogation
      while(!visited[temp] && indexes[temp] !== undefined){
        currentLength++;
        visited[temp] = true;
        temp++;
      }
      
      // backward propogation
      temp = tempNum-1;
      while(!visited[temp] && indexes[temp] !== undefined){
        currentLength++;
        visited[temp] = true;
        temp--;
      }
      
      maxLength = Math.max(maxLength, currentLength);
    }
    
    return maxLength;
};