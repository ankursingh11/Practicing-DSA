
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans;
        if(V == 0) return ans;
        
        queue<int> q;
        q.push(0);
        vector<bool> visited(V, false);
        visited[0] = true;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto nbr : adj[front]){
                if(!visited[nbr]){
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        
        return ans;
    }
};