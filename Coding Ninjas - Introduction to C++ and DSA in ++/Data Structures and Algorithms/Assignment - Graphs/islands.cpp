
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

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfs(int source, vector<bool>&visited){
         visited[source] = true;
         for(auto nbr : l[source]){
             if(!visited[nbr]) dfs(nbr, visited);
         }
    }

    void countIslands(){
        vector<bool> visited(V, false);

        int ans = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited);
                ans++;
            }
        }

        cout<<ans<<" ";
    }
};

int main() {
    // Write your code here
    int v, e;
    cin>>v>>e;

    if(e == 0){
        cout<<v;
        return 0;
    }

    Graph g(v);
    for(int i = 0; i < e; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v);
    }

    g.countIslands();

    return 0;
}