
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>&graph, vector<int>&visited, int node, int parent, int color){
    
    visited[node] = color;
    
    for(auto nbr : graph[node]){
        if(visited[nbr] == 0){
            bool subProb = dfs(graph, visited, nbr, node, 3 - color);
            if(!subProb) return false; 
        }else if(nbr != parent && color == visited[nbr]) return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> graph){
    
    int n = graph.size();
    vector<int> visited(n, 0);
    int color = 1;
    // for(int i = 0; i < n; i++){
    //     if(!visited[i]){
    //         bool smallAns = dfs(graph, visited, i, -1, color);
    //         if(smallAns) return true;
    //     }
    // }
    return dfs(graph, visited, 0, -1, color);
}