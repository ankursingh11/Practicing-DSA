
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
  
    void dfs(int node, vector<bool>&visited, vector<int>adj[], vector<int>&ans){
        
        visited[node] = true;
        ans.push_back(node);
        
        for(auto nbr : adj[node]){
            if(!visited[nbr]){
                dfs(nbr, visited, adj, ans);
            }
        }
        
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        if(V == 0) return ans;
        
        vector<bool>visited(V, false);
        ans.push_back(0);
        visited[0] = true;
        
        for(int i = 0; i < V; i++){
            for(auto nbr : adj[i]){
                if(!visited[nbr]){
                    dfs(nbr, visited, adj, ans);
                }
            }
        }
        
        return ans;
    }
};