
// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto ele : nums){
            if(mp.count(ele) > 0) return true;
            mp[ele]++;
        }

        return false;
    }
};