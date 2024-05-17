
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

    void printBFS_disconnected(int source, vector<bool>&visited){
        queue<int> q;

        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            cout<<f<<" ";
            for(auto nbr : l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void printBFS(){
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                printBFS_disconnected(i, visited);
            }
        }
    }
};

int main() {
    // Write your code here
    int v, e;
    cin>>v>>e;

    if(v == 0) return 0;


    Graph g(v);
    for(int i = 0; i < e; i++){
        int x, y;
        cin>>x>>y;
        g.addEdge(x, y);
    }

    g.printBFS();
    return 0;
}