
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*l;
    
    public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    
    void addEdge(int x, int y){
        l[x].push_back(y);
        // l[y].push_back(x);
    }
    
    bool dfs(int node, vector<bool>&visited, vector<bool>&stack){
        
        visited[node] = true;
        stack[node] = true;
        
        for(auto nbr : l[node]){
            if(stack[nbr]) return true; // contains a "BackEdge"
            else if(!visited[nbr]){
                bool nbrFoundCycle = dfs(nbr, visited, stack);
                if(nbrFoundCycle) return true;
            }
        }
        stack[node] = false;
        return false;
    }
    
    bool hasCycle(){
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);
        
        return dfs(1, visited, stack);
    }
};

bool solve(int n, vector<vector<int>>edges) {
    Graph g(n+1);
    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        g.addEdge(x, y);
    }
    
    return g.hasCycle();
}