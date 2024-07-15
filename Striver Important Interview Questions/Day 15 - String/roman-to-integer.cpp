
// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        
        int ans = 0;
        int n = s.size();
        if(n == 0) return ans;

        unordered_map<char, int> romanToIntegerMapping = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        for(int i = 0; i < n; ){
            if(i+1 < n && romanToIntegerMapping[s[i]] < romanToIntegerMapping[s[i+1]]){
                ans += romanToIntegerMapping[s[i+1]] - romanToIntegerMapping[s[i]];
                i+=2;  
            }else{
                ans += romanToIntegerMapping[s[i]];
                i+=1;
            } 
        }

        return ans;
    }
};