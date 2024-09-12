
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    let len = numbers.length;
    let i = 0, j = len-1;
    while(i < j){
        let currSum = numbers[i] + numbers[j];
        
        if(currSum === target){
            return [i+1, j+1];
        }else if(currSum < target) i++;
        else j--;
    }
    return [];
};