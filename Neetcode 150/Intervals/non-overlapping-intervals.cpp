
// https://leetcode.com/problems/non-overlapping-intervals/description/

bool comp(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int ans = -1;
        int size = intervals.size();
        if(size == 0) return ans;

        // sorting accoring to second element in array
        sort(intervals.begin(), intervals.end(), comp);

        auto prev = intervals[0];
        for(auto ele : intervals){
            if(prev[1] > ele[0]) ans++;
            else prev = ele;
        }
        
        return ans;
    }
};