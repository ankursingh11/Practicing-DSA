

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

    void dfs(int source, vector<bool>&visited, vector<int>& currConnectedComponent){
        visited[source] = true;
        currConnectedComponent.push_back(source);
        for(auto nbr : l[source]){
            if(!visited[nbr]){
                dfs(nbr, visited, currConnectedComponent);
            }
        }
    }

    void allConnectedComponents(){
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                vector<int> currConnectedComponent;
            dfs(i, visited, currConnectedComponent);
            if(currConnectedComponent.size() > 0){
                for(auto ele : currConnectedComponent) cout<<ele<<" ";
                cout<<endl;
            }
            }
            
        }
    }
};

int main() {
    int v, e;
    cin>>v>>e;

    if(v == 0 && e == 0){
        return 0;
    }

    Graph g(v);
    for(int i = 0; i < e; i++){
        int x, y;
        cin>>x>>y;
        g.addEdge(x, y);
    }

    g.allConnectedComponents();

    return 0;
}