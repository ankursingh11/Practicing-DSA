
// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }

    void solve(string s, vector<vector<string>>&ans, vector<string>&smallAns, int index){
        if(index == s.size()){
            ans.push_back(smallAns);
            return;
        }

        for(int i = index; i < s.size(); i++){
            if(isPalindrome(s, index, i)){
                smallAns.push_back(s.substr(index, i-index+1));
                solve(s, ans, smallAns, i+1);
                smallAns.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int size = s.size();
        if(size == 0) return ans;
        vector<string> smallAns;
        solve(s, ans, smallAns, 0);
        return ans;
    }
};