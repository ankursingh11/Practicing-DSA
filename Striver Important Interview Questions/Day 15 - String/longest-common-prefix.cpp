
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& words) {
        
        string ans = "";
        int n = words.size();
        if(n == 0) return ans;

        string smallestWord = words[0];
        for(int i = 1; i < n; i++){
            if(words[i].size() < smallestWord.size()) smallestWord = words[i];
        }

        for(int i = 0; i < smallestWord.size(); i++){
            for(int j = 0; j < n; j++){
                if(words[j][i] != smallestWord[i]) return ans;
            }
            ans += smallestWord[i];
        }

        return ans;
    }
};