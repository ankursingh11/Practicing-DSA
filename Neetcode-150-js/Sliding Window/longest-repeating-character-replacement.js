
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    const len = s.length;
    if(len === 0) return 0;

    const map = {};
    let left = 0, right = 0, maxFreq = 0, ans = 0;
    while(right < len){
        map[s[right]] = (map[s[right]] === undefined) ? 1 : map[s[right]]+1;
        maxFreq = Math.max(maxFreq, map[s[right]]);

        if((right-left+1)-maxFreq > k){
            map[s[left]]--;
            left++;
        }

        ans = Math.max(ans, (right-left+1));
        right++;
    }

    return ans;
};