
// https://leetcode.com/problems/valid-anagram/description/

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

function sortString(s){
    return s.split("").sort().join("");
}

var isAnagram = function(s, t) {
    let sSorted = sortString(s);
    let tSorted = sortString(t);
    return sSorted === tSorted;
};