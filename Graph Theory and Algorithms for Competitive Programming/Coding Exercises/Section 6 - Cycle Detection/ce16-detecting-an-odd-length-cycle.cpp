


#include<bits/stdc++.h>
using namespace std;

bool hasOddCycle(vector<vector<int>>&graph, vector<int>&visited, int node, int parent, int color){
    
    visited[node] = color;
    
    for(auto nbr : graph[node]){
        if(visited[nbr] == 0){
            bool subProblem = hasOddCycle(graph, visited, nbr, node, 3-color);
            if(subProblem) return false;
        }else if(nbr != parent && color == visited[nbr]) return false;
    }
    
    return true;
}


bool solve(vector<vector<int>> graph){
    
    int n = graph.size();
    vector<int> visited(n, 0);
    
    bool ans = hasOddCycle(graph, visited, 0, -1, 1);
    if(ans) return false;
    return true;
}