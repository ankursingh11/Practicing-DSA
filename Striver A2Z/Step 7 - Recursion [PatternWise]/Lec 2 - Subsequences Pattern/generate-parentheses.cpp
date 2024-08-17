
// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:

    vector<string> ans;

    void solve(int n, int open, int close, string curr){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }

        if(open < n) solve(n, open+1, close, curr+'(');
        if(open > close) solve(n, open, close+1, curr+')');
        return;
    }

    vector<string> generateParenthesis(int n) {
        // vector<string> ans;
        // if(!n) return ans;
        int open = 0, close = 0;
        solve(n, open, close, "");
        return ans;
    }
};