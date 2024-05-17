
// https://www.naukri.com/code360/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;
    for(auto queries : q){
        int queryType = queries[0];
        if(queryType == 0){
            int ele = queries[1];
            pq.push(ele);
        }else{
            if(pq.empty()) cout<<"-1";
            else{
                int minElement = pq.top();
                pq.pop();
                ans.push_back(minElement);
            }
        }
    }

    return ans;
}
