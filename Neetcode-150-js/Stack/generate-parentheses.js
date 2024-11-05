
// https://leetcode.com/problems/generate-parentheses/description/

/**
 * @param {number} n
 * @return {string[]}
 */

var helper = function(n, open, close, s, ans){
    if(open === n && close === n){
        ans.push(s);
        return;
    }

    if(open < n) helper(n, open+1, close, s+"(", ans);
    if(open > close) helper(n, open, close+1, s+")", ans);
}


var generateParenthesis = function(n) {
    const ans = [];
    helper(n, 0, 0, "", ans);
    return ans;
};