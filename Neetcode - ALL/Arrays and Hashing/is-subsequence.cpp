
// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();

        if(s.empty() && t.empty()) return true;

        int i = 0;
        for(int j = 0; j < tLen; j++){
            if(s[i] == t[j]) i++;
            if(i == sLen) return true;
        }

        return false;
    }
};