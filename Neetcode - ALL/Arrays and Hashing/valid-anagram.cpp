
// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int sLen = s.size();
        int tLen = t.size();

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (sLen == tLen) && (s == t);
    }
};