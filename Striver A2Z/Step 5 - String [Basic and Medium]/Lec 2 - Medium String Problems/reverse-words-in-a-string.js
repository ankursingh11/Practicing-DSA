
// https://leetcode.com/problems/reverse-words-in-a-string/

/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(str) {
    return str.trim().split(" ").filter(ele => ele !== "").reverse().join(" ");
};
