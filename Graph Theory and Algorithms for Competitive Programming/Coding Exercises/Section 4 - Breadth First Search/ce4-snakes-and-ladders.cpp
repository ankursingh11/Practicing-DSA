
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
    }
    
    int minCostPath(int source, int dest){
        queue<int> q;
        q.push(source);
        vector<bool> visited(V, false);
        visited[source] = true;
        vector<int> dist(V, 0);
        dist[source] = 0;
        
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            for(auto nbr : l[f]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                    dist[nbr] = dist[f] + 1;
                }
            }
        }
        
        return dist[dest];
    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    
    vector<int> board(n+1, 0);
    
    for(auto ele : snakes){
        int s = ele.first;
        int e = ele.second;
        board[s] = e - s;
    }
    
    for(auto ele : ladders){
        int s = ele.first;
        int e = ele.second;
        board[s] = e - s;
    }
    
    Graph g(n+1);
    
    for(int u = 1; u < n; u++){
        for(int dice = 1; dice <= 6; dice++){
            int v = u + dice;
            v = v + board[v];
            if(v <= n) g.addEdge(u, v);
        }
    }
    
    return g.minCostPath(1, n);
}
