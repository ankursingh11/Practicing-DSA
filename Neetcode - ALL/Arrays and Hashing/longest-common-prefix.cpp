
// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ans = "";
        if(strs.size() == 0) return ans;

        int size = strs.size();

        // finding the shortest word first
        string shortestWord = strs[0];
        for(auto word : strs){
            if(word.size() <= shortestWord.size()){
                shortestWord = word;
            }
        }

        // finding the common prefix
        for(int i = 0; i < shortestWord.size(); i++){
            bool flag = true;
            for(auto word : strs){
                if(word[i] != shortestWord[i]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            if(flag) ans += shortestWord[i];
        }

        return ans;
        
    }
};