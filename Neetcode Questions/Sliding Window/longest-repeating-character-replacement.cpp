
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxLength = -0;
        int size = s.size();
        if(size == 0) return maxLength;

        int left = 0, right = 0, maxFreq = 0;
        unordered_map<char, int> mp;
        while(right < size){
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            // (right-left+1) = window size
            // invalid window 
            while((right-left+1) - maxFreq > k){
                mp[s[left]]--;
                left++;
            }

            maxLength = max(maxLength, (right-left+1));
            right++;
        }

        return maxLength;
    }
};