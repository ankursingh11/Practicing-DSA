
// https://leetcode.com/problems/valid-palindrome/description/

/**
 * @param {string} s
 * @return {boolean}
 */
var getAlNum = function(s){
  let ans = "";
  for(let i = 0; i < s.length; i++){
    if(s[i].match(/[a-z0-9]/)){
      ans += s[i];
    }
  }
  return ans;
}

var checkPalindrome = function(s){
  let i = 0, j = s.length-1;
  while(i <= j){
    if(s[i++] !== s[j--]) return false;
  }
  return true;
}

var isPalindrome = function(s) {
    const sLowerTrim = s.toLowerCase().trim();
    const sAlNum = getAlNum(sLowerTrim);
    return checkPalindrome(sAlNum);
};