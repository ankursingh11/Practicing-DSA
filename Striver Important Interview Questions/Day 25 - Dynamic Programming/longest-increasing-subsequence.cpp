
// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int ans = 0;
        int n = nums.size();
        if(n == 0) return ans;

        vector<int> LIS(n, 1);
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(nums[i] < nums[j]){
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        ans = *max_element(LIS.begin(), LIS.end());
        return ans;
    }
};