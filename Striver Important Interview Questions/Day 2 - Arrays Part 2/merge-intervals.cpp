
// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int size = intervals.size();
        if(size == 0) return ans;

        sort(intervals.begin(), intervals.end());

        auto startingInterval = intervals[0];
        for(int i = 1; i < size; i++){
            if(startingInterval[1] >= intervals[i][0]){
                startingInterval[0] = min(startingInterval[0], intervals[i][0]);
                startingInterval[1] = max(startingInterval[1], intervals[i][1]);
            }else{
                ans.push_back(startingInterval);
                startingInterval = intervals[i];
            }
        }

        ans.push_back(startingInterval);
        return ans;
    }
};