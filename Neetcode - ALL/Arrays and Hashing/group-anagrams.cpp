
// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        if(strs.size() == 0) return ans;
        
        unordered_map<string, vector<string>> mp;
        for(auto word : strs){
            auto originalWord = word;
            sort(word.begin(), word.end());
            mp[word].push_back(originalWord);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};