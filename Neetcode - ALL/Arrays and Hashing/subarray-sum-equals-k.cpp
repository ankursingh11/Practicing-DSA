
// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

       unordered_map<int, int> mp;
       mp[0] = 1;
       int currSum = 0, ans = 0;
       for(auto num : nums){
        currSum += num;
        if(mp.count(currSum-k) > 0) ans += mp[currSum - k];
        mp[currSum]++;
       } 

       return ans;
    }
};