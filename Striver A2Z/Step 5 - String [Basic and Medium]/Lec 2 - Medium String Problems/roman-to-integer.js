
// https://leetcode.com/problems/roman-to-integer/

/**
 * @param {string} s
 * @return {number}
 */

const mapping = {
    'I' : 1,
    'V' : 5,
    'X' : 10,
    'L' : 50,
    'C' : 100,
    'D' : 500,
    'M' : 1000 
}

var romanToInt = function(str) {
    let ans = 0;
    for(let i = 0; i < str.length; ){
        if(mapping[str[i]] < mapping[str[i+1]]){
            ans += (mapping[str[i+1]] - mapping[str[i]]);
            i+=2;
        }else {
            ans += mapping[str[i]];
            i+=1;
        }
    }
    return ans;
};