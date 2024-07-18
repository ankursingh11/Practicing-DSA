
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:

    void findLPS(string pattern, vector<int>&lps){
        int n = pattern.size();
        int i = 1;
        int len = 0;
        
        while(i < n){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0) len = lps[len-1];
                else i++;
            }
        }
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        vector<int> lps(n, 0);
        findLPS(needle, lps);

        int i = 0, j = 0;
        while(i < m){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }

            if(j == n) return (i-j);
            else if(i < m && haystack[i] != needle[j]){
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }

        return -1;

    }
};