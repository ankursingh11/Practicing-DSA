
// https://neetcode.io/problems/meeting-schedule-ii

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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        int minRooms = 0;
        int size = intervals.size();
        if(size == 0) return minRooms;

        vector<int> startTimes, endTimes;
        for(int i = 0; i < size; i++){
            startTimes.push_back(intervals[i].start);
            endTimes.push_back(intervals[i].end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int s = 0, e = 0;
        int countRooms = 0;
        while(s < size){
            if(startTimes[s] < endTimes[e]){
                countRooms++;
                minRooms = max(minRooms, countRooms);
                s++;
            }else{
                countRooms--;
                e++;
            }
        }

        return minRooms;
    }
};
