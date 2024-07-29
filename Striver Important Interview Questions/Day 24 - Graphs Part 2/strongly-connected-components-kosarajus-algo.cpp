
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

class Solution
{
	public:
	
	void dfs(vector<vector<int>>&adj, vector<bool>&visited, int node, stack<int>&st){
	    visited[node] = true;
	    for(auto nbr : adj[node]){
	        if(!visited[nbr]) dfs(adj, visited, nbr, st);
	    }
	    st.push(node);
	    return;
	}
	
	void rev_dfs(vector<vector<int>>&adj, vector<bool>&visited, int node){
	    visited[node] = true;
	    for(auto nbr : adj[node]){
	        if(!visited[nbr]) rev_dfs(adj, visited, nbr);
	    }
	    return;
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(adj, visited, i, st);
            }
        }
        
        vector<vector<int>> transpose(V);
        for(int i = 0; i < V; i++){
            visited[i] = false;
            for(auto nbr : adj[i]) transpose[nbr].push_back(i);
        }
        
        int count = 0;
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            if(!visited[node]){
                count++;
                rev_dfs(transpose, visited, node);
            }
        }
        
        return count;
    }
};