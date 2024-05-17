
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> rooms, vector<bool>&visited, int node){
    visited[node] = true;
    
    for(auto key : rooms[node]){
        if(!visited[key]) dfs(rooms, visited, key);
    }
}

bool canVisitAllRooms(vector<vector<int>> rooms) {
   
   int n = rooms.size();
   vector<bool> visited(n, false);
   
   dfs(rooms, visited, 0);
   
   for(int i = 0; i < n; i++){
       if(!visited[i]) return false;
   }
   
   return true;
}