
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
    
    bool hasCycleHelper(int node, vector<bool>&visited, int parent){
        visited[node] = true;
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool nbrHasCycle = hasCycleHelper(nbr, visited, node);
                if(nbrHasCycle) return true;
            }else if(nbr != parent){
                return true;
            }
        }
        return false;
    }
    
    bool hasCycle(){
        vector<bool> visited(V, false);
        return hasCycleHelper(1, visited, -1);
    }
};

bool solve(int n, vector<vector<int> > edges) {
    Graph g(n+1);
    for(auto edge : edges){
        int x = edge[0], y = edge[1];
        g.addEdge(x, y);
    }
    
    return g.hasCycle();
    
}