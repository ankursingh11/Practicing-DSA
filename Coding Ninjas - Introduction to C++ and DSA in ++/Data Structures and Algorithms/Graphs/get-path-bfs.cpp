
#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int>*path_BFS(int **edges, int n, int v1, int v2){
    queue<int>q;
    q.push(v1);
    
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;
    
    visited[v1] = true;
    vector<int>*ans = new vector<int>();
    unordered_map<int, int> parent;
    bool flag = false;
    
    while(!q.empty() && !flag){
        int cv = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(i == cv) continue;
            if(!visited[i] && edges[cv][i] == 1){
                q.push(i);
                visited[i] = true;
                parent[i] = cv;
                if(i == v2){
                    flag = true;
                    break;
                }
            }
        }
    }
    
    if(!flag) return NULL;
    else{
        int current = v2;
        ans->push_back(current);
        while(current!=v1){
            current = parent[current];
            ans->push_back(current);
        }
        return ans;
    }
}

int main()
{
  int V, E;
  cin >> V >> E;

  int **edges = new int*[V];
    for(int i = 0; i < V; i++){
        edges[i] = new int[V];
        for(int j = 0; j < V; j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < E; i++){
        int s, d;
        cin>>s>>d;
        edges[s][d] = 1;
        edges[d][s] = 1;
    }
    
    int v1, v2;
    cin>>v1>>v2;
    
    vector<int> *ans = path_BFS(edges, V, v1, v2);
    
    if(ans){
        for(int i = 0; i < ans->size(); i++) cout<<ans->at(i)<<" ";
    }
    
    for(int i = 0; i < V; i++) delete []edges[i];
    delete []edges;
  return 0;
}