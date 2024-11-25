
// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int, int> mp;
        for(auto ele : nums) mp[ele]++;

        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        while(k--){
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};