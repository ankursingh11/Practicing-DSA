
// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        if(s.size() == 0) return ans;

        stringstream ss(s);
        string temp = "";
        vector<string> words;
        while(ss >> temp) words.push_back(temp);

        for(int i = words.size()-1; i >= 0; i--){
            if(i == 0) ans += words[i];
            else ans += words[i] + " ";
        }

        return ans;

    }
};