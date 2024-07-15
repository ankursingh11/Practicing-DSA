
// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        if(n == 0) return ans;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int ansLength = 1;

        // word of size 1 are palindrome
        for(int i = 0; i < n; i++) dp[i][i] = true;

        // word of size 2
        int startIndex = 0;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                startIndex = i;
                ansLength = 2;
            }
        }

        // word of size 3 and so on...
        for(int k = 3; k <= n; k++){
            for(int i = 0; i < n-k+1; i++){
                int j = i+k-1;

                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    startIndex = i;
                    ansLength = k;
                }
            }
        }

        // printing word
        for(int i = startIndex; i < startIndex + ansLength; i++) ans += s[i];

        return ans;
    }
};