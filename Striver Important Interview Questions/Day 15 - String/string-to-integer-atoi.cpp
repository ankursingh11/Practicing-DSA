
// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int n = s.size();
        if(n == 0) return ans;

        int sign = 1, index = s.find_first_not_of(' ');
        if(index == -1) return ans;
        if(s[index] == '+' || s[index] == '-'){
            sign = (s[index++] == '+' )? 1 : -1;
        }

        while(index < n && isdigit(s[index])){
            ans = ans*10 + (s[index++] - '0');
            if(sign*ans > INT_MAX) return INT_MAX;
            if(sign*ans < INT_MIN) return INT_MIN;
        }

        return ans*sign;
    }
};