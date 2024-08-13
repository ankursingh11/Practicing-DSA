// https://leetcode.com/problems/largest-odd-number-in-string/

var isOdd = (num) => num % 2 !== 0;

var largestOddNumber = function (num) {
  for (let i = num.length - 1; i >= 0; i--) {
    if (isOdd(+num[i])) {
      return num.substr(0, i + 1);
    }
  }
  return "";
};
