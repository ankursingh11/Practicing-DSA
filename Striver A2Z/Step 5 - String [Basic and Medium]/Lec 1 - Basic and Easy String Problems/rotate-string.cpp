
// https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int goalLen = goal.size();
        if(n != goalLen) return false;

        int x = 0;
        while(x < n){
            if(goal.substr(0, n-x) == s.substr(x, n-x)) break;
            else x++;
        }

        return s.substr(0, x) == goal.substr(n-x, x) ? true : false;

        
    }
};