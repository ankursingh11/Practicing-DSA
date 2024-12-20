
// https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(auto stone : stones) pq.push(stone);

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y) continue;
            else if(y > x) pq.push(y-x);
        }

        if(!pq.empty()) return pq.top();
        return 0;
    }
};