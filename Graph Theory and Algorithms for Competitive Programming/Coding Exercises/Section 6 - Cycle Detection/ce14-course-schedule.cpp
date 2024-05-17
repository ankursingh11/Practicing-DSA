
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
            if(stack[nbr]) return true;
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
        
        for(int i = 0; i < V; i++){
            if(dfs(i, visited, stack)) return false;
        }
        return true;
    }
};

bool canFinish(vector<vector<int>> prerequisites,int numCourses) {
    Graph g(numCourses);
    for(auto edge : prerequisites){
        int x = edge[0];
        int y = edge[1];
        g.addEdge(y, x);
    }
    
    return g.hasCycle();
}