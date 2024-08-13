
// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if(sLen != tLen) return false;

        unordered_map<char, char> mp1, mp2;
        bool flag = true;
        for(int i = 0; i < sLen; i++){
            if( (mp1.count(s[i]) || mp2.count(t[i])) && (mp1[s[i]] != t[i] || mp2[t[i]] != s[i])){
                flag = false;
            }else{
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
        }
        return flag;
    }
};