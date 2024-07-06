
// https://neetcode.io/problems/valid-tree


class Graph{
    public :
    int V;
    list<int>*l;

    public :
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool hasCycle(int node, int parent, vector<bool>&visited){

        visited[node] = true;
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool nbrHasCycle = hasCycle(nbr, node, visited);
                if(nbrHasCycle) return true;
            }else if(nbr != parent) return true;
        }

        return false;
    }

    bool isGraphTree(int source){

        vector<bool>visited(V, false);

        if(hasCycle(source, -1, visited)) return false;
        
        // check if all connected
        for(int i = 0; i < V; i++){
            if(!visited[i]) return false;
        }

        return true;
    }
};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        Graph g(n);

        for(auto edge : edges){
            g.addEdge(edge[0], edge[1]);
        }

        if(g.isGraphTree(0)) return true;
        return false;
    }
};
