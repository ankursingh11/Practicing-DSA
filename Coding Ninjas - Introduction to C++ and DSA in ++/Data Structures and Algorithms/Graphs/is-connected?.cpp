
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;

    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs(int source, vector<bool>&visited){
        visited[source] = true;
        for(auto nbr : l[source]){
            if(!visited[nbr]){
                dfs(nbr, visited);
            }
        }
    }

    bool isConnected(){
        vector<bool> visited(V, false);
        dfs(0, visited);
        

        for(int i = 0; i < V; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};

int main() {
    int v, e;
    cin>>v>>e;

    if(v == 0 && e == 0){
        cout<<"true";
        return 0;
    }

    Graph g(v);
    for(int i = 0; i < e; i++){
        int x, y;
        cin>>x>>y;
        g.addEdge(x, y);
    }

    if(g.isConnected()) cout<<"true";
    else cout<<"false";

    return 0;
}