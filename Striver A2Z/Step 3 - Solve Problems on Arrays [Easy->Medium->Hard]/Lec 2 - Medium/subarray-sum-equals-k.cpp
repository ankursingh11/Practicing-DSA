
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count = 0;
        int n = nums.size();
        if(n == 0) return count;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        for(int i = 0; i < n; i++){
            currSum += nums[i];
            if(mp.count(currSum-k) > 0) count += mp[currSum-k];
            mp[currSum]++;
        }
        return count;
    }
};