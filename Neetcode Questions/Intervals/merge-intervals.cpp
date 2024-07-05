
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int size = intervals.size();
        vector<vector<int>> ans;
        if(size == 0) return ans;

        sort(intervals.begin(), intervals.end());

        auto currInterval = intervals[0];

        for(int i = 1; i < size; i++){
            if(intervals[i][0] <= currInterval[1]){
                currInterval[0] = min(intervals[i][0], currInterval[0]);
                currInterval[1] = max(intervals[i][1], currInterval[1]);
            }else{
                ans.push_back(currInterval);
                currInterval = intervals[i];
            }
        }

        ans.push_back(currInterval);
        return ans;
    }
};