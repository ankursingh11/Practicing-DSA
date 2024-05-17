
// https://leetcode.com/problems/top-k-frequent-elements/description/

bool comparePairs(pair<int, int> a, pair<int, int> b){
    return b.first > a.first;
}

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int size = nums.size();
        vector<int> ans;
        if(size == 0) return ans;

        priority_queue< pair<int, int>, vector<pair<int, int>>, decltype(&comparePairs)> pq(comparePairs);
        unordered_map<int, int> mp;
        for(auto ele : nums) mp[ele]++;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};