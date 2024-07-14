
// https://www.udemy.com/course/graph-theory-algorithms-for-competitive-programming/learn/quiz/5268982#overview

#include<bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges){
    
    // preparing the adj list and visited array
    map<int, vector<int>> mp;
    vector<bool> visited(n+1, false);
    
    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    
    // prepare a set of q and mark node 1 as visited
    visited[1] = true;
    queue<set<int>> q;
    set<int> s;
    s.insert(1);
    q.push(s);
    
    int i = 0; // for traversing the sequence array
    while(!q.empty() && i < sequence.size()){
        
        // case 1
        if(visited[sequence[i]]) return false;
        visited[sequence[i]] = true;
        
        // case 2
        if(q.front().size() == 0) return false;
        q.pop();
        
        // case 3
        if(q.front().find(sequence[i]) == q.front().end()){
            return false;
        }
        s.clear();
        
        // case 4
        for(auto nbr : mp[sequence[i]]){
            if(!visited[nbr]) s.insert(nbr);
        }
        if(s.size() > 0){
            set<int> temp = s;
            q.push(temp);
        }
        s.clear();
        
        q.front().erase(sequence[i]);
        i++;
    }
    
    return true;
}