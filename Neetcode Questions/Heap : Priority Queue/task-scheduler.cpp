
// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        queue<vector<int>> q;
        priority_queue<int> pq;
        vector<int> counter(26, 0);

        for(auto task : tasks) counter[task - 'A']++;
        for(auto counts : counter){
            if(counts > 0) pq.push(counts);
        }

        int time = 0;
        while(!q.empty() || !pq.empty()){
            ++time;
            if(!pq.empty()){
                if(pq.top()-1 > 0){
                    q.push({pq.top()-1, time+n});
                }
                pq.pop();
            }

            if(!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }

        return time;
    }
};