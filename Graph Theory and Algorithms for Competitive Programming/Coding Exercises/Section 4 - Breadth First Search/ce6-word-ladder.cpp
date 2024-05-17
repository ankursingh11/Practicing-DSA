
#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    
    unordered_set<string> s;
    for(auto word : wordList) s.insert(word);
    
    queue<string> q;
    q.push(beginWord);
    int ans = 0;
    while(!q.empty()){
        int n = q.size();
        vector<string> v;
        ans++;
        for(int i = 0; i < n; i++){
            string str = q.front();
            
            if(str == endWord) return ans;
            
            for(int j = 0; j < str.size(); j++){
                char ch = str[j];
                
                for(int k = 0; k < 26; k++){
                    str[j] = (char)(97+k);
                    if(s.find(str) != s.end()){
                        v.push_back(str);
                        s.erase(str);
                    }
                }
                str[j] = ch;
            }
            q.pop();
        }
        
        for(auto ele : v) q.push(ele);
    }
    
    return 0;
}