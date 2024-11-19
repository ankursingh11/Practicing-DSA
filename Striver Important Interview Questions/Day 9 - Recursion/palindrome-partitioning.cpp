
// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:

    bool isPalindrome (string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>&ans, vector<string>&smallAns, int si){
        if(si == s.size()){
            ans.push_back(smallAns);
            return;
        }

        for(int i = si; i < s.size(); i++){
            if(isPalindrome(s, si, i)){
                smallAns.push_back(s.substr(si, i-si+1));
                solve(s, ans, smallAns, i+1);
                smallAns.pop_back();
            }
        }

        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size() == 0) return ans;

        vector<string> smallAns;
        solve(s, ans, smallAns, 0);
        return ans;
    }
};