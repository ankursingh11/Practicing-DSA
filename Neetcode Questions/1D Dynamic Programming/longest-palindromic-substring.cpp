
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {

        string ans = "";
        int size = s.size();
        if(size == 0 || size == 1) return s;

        vector<vector<bool>> dp(size, vector<bool>(size, false));

        // word of size 1 are always palindrome
        for(int i = 0; i < size; i++){
            dp[i][i] = true;
        }
        
        // word of size 2
        int startIndex = 0, maxLength = 1;
        for(int i = 0; i < size-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                startIndex = i;
                maxLength = 2;
            }
        }

        // word of size 3 onwards
        for(int k = 3; k <= size; k++){
            // start index
            for(int i = 0; i < size-k+1; i++){
                int j = i+k-1; // end index

                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    startIndex = i;
                    maxLength = k;
                }
            }
        }

        for(int i = startIndex; i < startIndex + maxLength; i++) ans += s[i];
        return ans;
    }
};