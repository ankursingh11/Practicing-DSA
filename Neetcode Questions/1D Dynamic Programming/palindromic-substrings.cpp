
// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        
        int ans = 1;
        int n = s.size();
        if(n == 1) return ans;
        
        vector<vector<bool>> table(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++){
            table[i][i] = true;
            ans++;
        }
        
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                table[i][i+1] = true;
                ans++;
            }
        }
        
        for(int k = 3; k <= n; k++){
            for(int i = 0; i < n-k+1; i++){
                int j = i+k-1;
                if(s[i] == s[j] && table[i+1][j-1]){
                    table[i][j] = true;
                    ans++;
                }
            }
        }
        
        return ans-1;
    }
};