
#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>edges){
    unordered_map<int, vector<int>> mp;
    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    
    int n = edges.size();
    for(auto it : mp){
        if(it.second.size() == n) return it.first;
    }
    
    return -1;
}