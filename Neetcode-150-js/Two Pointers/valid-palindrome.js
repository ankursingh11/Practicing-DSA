
// https://leetcode.com/problems/valid-palindrome/

/**
 * @param {string} s
 * @return {boolean}
 */

var getAlNum = (str) => {
    let result = "";
    let len = str.length;
    for(let i = 0; i < len; i++){
        if(str[i].match(/[a-z0-9]/)){
            result += str[i];
        }
    }
    return result;
}

var checkPalindrome = (str) => {
    let len = str.length;
    if(len === 0) return true;
    let i = 0, j= len-1;
    while(i < j){
        if(str[i++] !== str[j--]) return false;
    }
    return true;
}

var isPalindrome = function(s) {
    let sLower = s.toLowerCase().trim();
    let str = getAlNum(sLower);
    return checkPalindrome(str);
};