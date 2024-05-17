


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    
    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    int minCostPath(int start, int end){
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> dist(V, 0);
        
        q.push(start);
        visited[start] = true;
        dist[start] = 0;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            for(auto node : l[curr]){
                if(!visited[node]){
                    q.push(node);
                    visited[node] = true;
                    dist[node] = dist[curr] + 1;
                }
            }
        }
        
        return dist[end];
    }
};


int messageRoute(int n, vector<vector<int>>edges){
    
    Graph g(n+1);
    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        g.addEdge(x, y);
    }
    
    return g.minCostPath(1, n)+1;
}