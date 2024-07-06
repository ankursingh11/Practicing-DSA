#include<bits/stdc++.h>
using namespace std;


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

vector<bool> DSU(vector<vector<int>>query)
{
    vector<int> parent(100000, -1);
    vector<bool> ans;
    
    for(auto q : query){
        int queryType = q[0];
        
        if(queryType == 1){  // union
            int u = q[1], v = q[2];
            unionSet(u, v, parent);
            
        }else if(queryType == 2){ // find
            int u = q[1], v = q[2];
            bool sameSet = unionSet(u, v, parent);
            ans.push_back(sameSet);
        }
    }
    
    return ans;
}