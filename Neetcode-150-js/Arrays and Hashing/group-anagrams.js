
// https://leetcode.com/problems/group-anagrams/description/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */

function sortString(str){
    return str.split("").sort().join("");
}

var groupAnagrams = function(strs) {
    const map = {};
    for(const str of strs){
        let sortedStr = sortString(str);
        if(map[sortedStr]){
            map[sortedStr].push(str);
        }else map[sortedStr] = [str];
    }

    const response = [];
    for(const arr of Object.values(map)){
      response.push(arr);
    }
    return response;
};