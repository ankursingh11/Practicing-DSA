
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ansLength = 0;
        int n = s.size();
        if(n == 0) return ansLength;

        vector<int> index(256, -1);
        int left = 0, right = 0;
        while(right < n){
            if(index[s[right]] != -1) left = max(left, index[s[right]]+1);
            index[s[right]] = right;
            ansLength = max(ansLength, right-left+1);
            right++;
        }

        return ansLength;
    }
};