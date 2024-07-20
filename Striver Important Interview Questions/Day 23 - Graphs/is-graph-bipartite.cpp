
// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:

    bool checkBipartite(vector<vector<int>>&graph, vector<int>&visited, int child, int parent, int color){
        visited[child] = color;
        for(auto nbr : graph[child]){
            if(!visited[nbr]){
                bool isGraphBipartite = checkBipartite(graph, visited, nbr, child, 3-color);
                if(!isGraphBipartite) return false;
            }else if(nbr != parent && color == visited[nbr]) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        if(v == 0) return true;

        vector<int> visited(v, 0);
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                bool isGraphBipartite = checkBipartite(graph, visited, i, -1, 1);
                if(!isGraphBipartite) return false;
            }
        }

        return true;
    }
};