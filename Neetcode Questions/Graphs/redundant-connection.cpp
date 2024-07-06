
// https://leetcode.com/problems/redundant-connection/

class Solution {
public:

    int findSet(int u, vector<int>&parent){
        if(parent[u] == -1) return u;
        return findSet(parent[u], parent);
    }

    bool unionSet(int u, int v, vector<int>&parent){
        int s1 = findSet(u, parent);
        int s2 = findSet(v, parent);
        if(s1 != s2){
            parent[s2] = s1;
            return false;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int> ans;
        if(edges.size() == 0) return ans;

        int vertices = edges.size();
        vector<int> parent(vertices+1, -1);

        for(auto edge : edges){
            int u = edge[0], v = edge[1];

            int s1 = findSet(u, parent);
            int s2 = findSet(v, parent);

            if(s1 != s2){
                unionSet(u, v, parent);
            }else{
                // has a cycle
                // found backedges 
                ans.push_back(u);
                ans.push_back(v);
                return ans;
            }
        }

        return ans;
    }
};