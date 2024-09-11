
// https://leetcode.com/problems/group-anagrams/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */

var sortString = (str) => str.split('').sort().join('');

var groupAnagrams = function(strs) {
    const map = {};

    for(const str of strs){
        const strSorted = sortString(str);
        if(map[strSorted]){
            map[strSorted].push(str);
        }else map[strSorted] = [str];
    }

    const result = [];
    for(const key in map){
        result.push(map[key]);
    }
    return result;
};