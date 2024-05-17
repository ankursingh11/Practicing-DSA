
#include<bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    int v, e;
    cin>>v>>e;

    vector<vector<int>> edges(v, vector<int>(v, 0));
    for(int i = 0; i <e; i++){
        int u, v;
        cin>>u>>v;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }

    int ans = 0;
    for(int i = 0; i < v; i++){
        for(int j = i+1; j < v; j++){
            for(int k = j+1; k < v; k++){
                if(edges[i][j] == 1 && edges[j][k] == 1 && edges[k][i] == 1){
                    ans++;
                }
            }
        }
    }

    cout<<ans;
    return 0;
}