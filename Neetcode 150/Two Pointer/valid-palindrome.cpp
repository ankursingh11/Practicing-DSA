
// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:

    bool checkPalindrome(string s){
        int size = s.size();
        int i = 0, j = size-1;
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }

    bool isPalindrome(string str) {
        
        string cleanedString = "";
        for(auto  s : str){
            if(isalnum(s)) cleanedString += tolower(s);
        }

        // cout<<cleanedString;

        return checkPalindrome(cleanedString);
    }
};