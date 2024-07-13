
// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class meeting{
    public :
    int start;
    int end;
    int pos;
};

bool comp(meeting m1, meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    
    return false;
}

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        meeting intervals[n];
        
        for(int i = 0; i < n; i++) intervals[i] = {start[i], end[i], i+1};
        
        sort(intervals, intervals+n, comp);
        
        int count = 1;
        int lastEndTime = intervals[0].end;
        for(int i = 1; i < n; i++){
            if(intervals[i].start > lastEndTime){
                count++;
                lastEndTime = intervals[i].end;
            }
        }
        
        return count;
    }
};