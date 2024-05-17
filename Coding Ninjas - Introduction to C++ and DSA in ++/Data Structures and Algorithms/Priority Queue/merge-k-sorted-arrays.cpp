

#include<bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < input.size(); i++){
        vector<int>*curr = input.at(i);
        for(int j = 0; j < curr->size(); j++) pq.push(curr->at(j));
    }
    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
