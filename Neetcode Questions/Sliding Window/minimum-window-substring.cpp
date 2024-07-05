
// https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t == "" || t.size() > s.size()) return "";

        unordered_map<char, int> window, countT;
        for(auto ch : t) countT[ch]++;
        int have = 0, need = countT.size(), start = -1, minLength = INT_MAX;

        for(int l = 0, r = 0; r < s.size(); r++){
            char ch = s[r];
            window[ch]++;

            if(countT.find(ch) != countT.end() && window[ch] == countT[ch]) have++;

            while(have == need){
                if((r-l+1) < minLength){
                    start = l;
                    minLength = (r-l+1);
                }

                window[s[l]]--;

                if(countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) have--;

                l++;
            }
        }

        return minLength != INT_MAX ? s.substr(start, minLength) : "";
    }
};