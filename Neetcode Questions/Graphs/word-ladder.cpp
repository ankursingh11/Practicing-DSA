
// https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> s;
        for(auto word : wordList) s.insert(word);

        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            vector<string> v;
            int n = q.size();
            ans++;
            for(int i = 0; i < n; i++){
                string currentWord = q.front();
                q.pop();
                if(currentWord == endWord) return ans;

                for(int j = 0; j < currentWord.size(); j++){
                    char ch = currentWord[j];
                    for(int k = 0; k < 26; k++){
                        currentWord[j] = (char)(97+k);
                        if(s.find(currentWord) != s.end()){
                            v.push_back(currentWord);
                            s.erase(currentWord);
                        }
                    }
                    currentWord[j] = ch;
                }
            }
            for(auto word : v) q.push(word);
        }
        return 0;
    }
};