
// https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:

    bool checkEqualVectors(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freqS1(26, 0);
        for(int i = 0; i < s1.size(); i++) freqS1[s1[i] - 'a']++;

        int i = 0, j = 0;
        vector<int> freqS2(26, 0);
        while(j < s2.size()){
            freqS2[s2[j]-'a']++;

            if(j-i+1 == s1.size()){
                if(checkEqualVectors(freqS1, freqS2)) return true;
            }

            if(j-i+1 < s1.size()) j++;
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }

        return false;
    }
};