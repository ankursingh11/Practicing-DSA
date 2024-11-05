
// https://leetcode.com/problems/daily-temperatures/description/

/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
 
 Array.prototype.empty = function(){
   return this.length === 0;
 }
 
 Array.prototype.back = function(){
   return this[this.length-1];
 }
 
var dailyTemperatures = function(temperatures) {

    let len = temperatures.length;
    const answer = Array.from({length : len}, () => 0);
    if(len === 0) return answer;

    temperatures = temperatures.reverse();
    const stack = [0];
    
    for(let i = 1; i < len; i++){
      while(!stack.empty() && temperatures[i] >= temperatures[stack.back()]) stack.pop();
      
      if(stack.empty()) answer[i] = 0;
      else answer[i] = i - stack.back();
      
      stack.push(i);
    }
    
    return answer.reverse();
};