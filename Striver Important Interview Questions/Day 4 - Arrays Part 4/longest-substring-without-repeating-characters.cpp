
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        if(n == 0) return ans;

        int left = 0, right = 0;
        vector<int> arr(256, -1);

        while(right < n){
            if(arr[s[right]] != -1) left = max(left, arr[s[right]]+1);
            arr[s[right]] = right;
            ans = max(ans, (right-left+1));
            right++;
        }
        
        return ans;
    }
};