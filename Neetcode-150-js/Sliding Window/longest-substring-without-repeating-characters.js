
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let len = s.length;
    let ans = 0;
    if(len === 0) return ans;

    let left = 0, right = 0;
    const map = {};
    while(right < len){
        if(map[s[right]] !== undefined) left = Math.max(left, map[s[right]]+1);
        map[s[right]] = right;
        ans = Math.max(ans, (right-left+1));
        right++;
    }
    return ans;
};