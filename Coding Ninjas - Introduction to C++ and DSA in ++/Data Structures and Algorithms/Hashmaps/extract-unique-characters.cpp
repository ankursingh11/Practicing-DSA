

#include<bits/stdc++.h>

string uniqueChar(string str) {
	// Write your code here

    unordered_map<char, int> mp;
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        auto ch = str[i];
        if(mp.count(ch) == 0) ans = ans + ch;
        mp[ch]++;
    }

    return ans;
}