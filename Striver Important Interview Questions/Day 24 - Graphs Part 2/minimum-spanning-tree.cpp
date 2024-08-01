
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<int> key(V, INT_MAX), parent(V, -1);
        vector<bool> mstSet(V, false);
        key[0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int u = top[1];
            mstSet[u] = true;
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(weight < key[v] && !mstSet[v]){
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        
        return accumulate(key.begin(), key.end(), 0);
    }
};