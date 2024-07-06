
// https://neetcode.io/problems/meeting-schedule

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 bool comp(Interval &a, Interval &b){
    return a.end < b.end;
 }

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int size = intervals.size();
        if(size == 0) return true;

        sort(intervals.begin(), intervals.end(), comp);

        auto prev = intervals[0];
        for(int i = 1; i < size; i++){
            if(prev.end > intervals[i].start) return false;
            else prev = intervals[i];
        }

        return true;
    }
};
