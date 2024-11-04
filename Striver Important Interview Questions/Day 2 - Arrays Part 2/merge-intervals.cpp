
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> ans;
        if(size == 0) return ans;

        sort(intervals.begin(), intervals.end());
        auto currentInterval = intervals[0];
        for(int i = 1; i < size; i++){
            if(currentInterval[1] >= intervals[i][0]){
                currentInterval[0] = min(currentInterval[0], intervals[i][0]);
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
            }else{
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        ans.push_back(currentInterval);
        return ans;
    }
};