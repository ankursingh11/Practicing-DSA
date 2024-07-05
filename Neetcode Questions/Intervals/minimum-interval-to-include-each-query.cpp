
// https://leetcode.com/problems/minimum-interval-to-include-each-query/description/

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int> copy_queries = queries;
        sort(queries.begin(), queries.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;

        int i = 0;
        for(auto q : queries){
            // insert all those intervals which are valid for a q
            while(i < intervals.size() && intervals[i][0] <= q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r-l+1, r});
                i++;
            }

            // removing those whose size is not valid
            while(pq.size() && pq.top().second < q) pq.pop();

            if(pq.size()) mp[q] = pq.top().first;
            else mp[q] = -1;
        }

        vector<int> ans;
        for(auto q : copy_queries) ans.push_back(mp[q]);

        return ans;
    }
};