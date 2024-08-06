
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0) return ans;

        sort(intervals.begin(), intervals.end());

        auto currInterval = intervals[0];
        for(int i = 1; i < n; i++){
            if(currInterval[1] >= intervals[i][0]){
                currInterval[0] = min(currInterval[0], intervals[i][0]);
                currInterval[1] = max(currInterval[1], intervals[i][1]);
            }else{
                ans.push_back(currInterval);
                currInterval = intervals[i];
            }
        }
        ans.push_back(currInterval);
        return ans;
    }
};