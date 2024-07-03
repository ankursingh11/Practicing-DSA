
// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution {
public:

    void dfs(vector<vector<int>>&graph, int V, vector<vector<int>>&allPaths, vector<bool>&visited, vector<int>&path, int source){
        
        if(source == V-1){
            allPaths.push_back(path);
            return;
        }

        visited[source] = true;
        for(auto nbr : graph[source]){
            if(!visited[nbr]){
                path.push_back(nbr);
                dfs(graph, V, allPaths, visited, path, nbr);
                path.pop_back();
            }
        }

        visited[source] = false;
        return;
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> allPaths;
        if(V == 0) return allPaths;

        vector<bool> visited(V, false);
        vector<int> path;
        path.push_back(0);

        for(auto nbr : graph[0]){
            if(!visited[nbr]){
                path.push_back(nbr);
                dfs(graph, V, allPaths, visited, path, nbr);
                path.pop_back();
            }
        }

        return allPaths;
        
    }
};