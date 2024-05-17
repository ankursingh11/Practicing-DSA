
// https://leetcode.com/problems/concatenation-of-array/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(2*size, 0);
        if(size == 0) return ans;

        for(int i = 0; i < size; i++){
            ans[i] = ans[i + size] = nums[i];
        }

        return ans;
    }
};