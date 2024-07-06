
// https://neetcode.io/problems/count-connected-components

class Graph{
    int V;
    list<int>* l;

    public :
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs(int node, vector<bool>&visited){
        visited[node] = true;

        for(auto nbr : l[node]){
            if(!visited[nbr]) dfs(nbr, visited);
        }
    }

    int countConnected(){
        vector<bool> visited(V, false);

        int count = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, visited);
                count++;
            }
        }

        return count;
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Graph g(n);

        for(auto edge : edges){
            g.addEdge(edge[0], edge[1]);
        }

        int connectedComponents = g.countConnected();
        return connectedComponents;
    }
};
