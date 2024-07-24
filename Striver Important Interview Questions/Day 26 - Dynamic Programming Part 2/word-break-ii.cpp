
// https://leetcode.com/problems/word-break-ii/description/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;

        for(auto word : wordDict){
            if(s.substr(0, word.size()) == word){
                if(s.size() == word.size()){
                    result.push_back(word);
                }else{
                    vector<string> temp = wordBreak(s.substr(word.size()), wordDict);
                    for(auto t : temp) result.push_back(word + " " + t);
                }
            }
        }

        return result;
    }
};