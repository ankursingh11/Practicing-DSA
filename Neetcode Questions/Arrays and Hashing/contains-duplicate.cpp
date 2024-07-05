
// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            if(mp.find(num) != mp.end()) return true;
            mp[num]++;
        }
        return false;
    }
};