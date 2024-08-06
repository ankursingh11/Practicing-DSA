
// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        vector<int> freq(n+1, 0);
        for(auto ele : nums) freq[ele]++;
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] == 0) return i;
        }
        return -1;
    }
};