
// https://leetcode.com/problems/k-closest-points-to-origin/description/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for(auto point : points){
            int x = point[0];
            int y = point[1];
            int dist = x*x + y*y;
            pq.push({dist, {x, y}});
        }

        vector<vector<int>> ans;
        while(k--){
            auto smallAns = pq.top();
            pq.pop();
            int x = smallAns.second.first;
            int y = smallAns.second.second;
            ans.push_back({x, y});
        }
        
        return ans;
    }
};