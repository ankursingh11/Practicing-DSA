
// https://leetcode.com/problems/word-break/description/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> st;
        for(auto word : wordDict) st.insert(word);

        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j]){
                    string word = s.substr(j, i-j); // i > j
                    if(st.find(word) != st.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};