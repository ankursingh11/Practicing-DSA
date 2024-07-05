
// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int size = strs.size();
        vector<vector<string>> ans;
        if(size == 0) return ans;

        unordered_map<string, vector<string>> mp;
        for(auto str : strs){
            string original = str;
            sort(str.begin(), str.end());
            mp[str].push_back(original);
        }

        for(auto it : mp) ans.push_back(it.second);

        return ans;
    }
};