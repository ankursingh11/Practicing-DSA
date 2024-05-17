
#include<bits/stdc++.h>
using namespace std;

int minTrioDegree(int n, vector<vector<int>> edges) {
    
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
    vector<int> degree(n+1, 0);
    for(auto edge : edges){
        int x = edge[0];
        int y = edge[1];
        degree[x]++;
        degree[y]++;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    
    int ans = INT_MAX;
    for(int i = 0; i < n+1; i++){
        for(int j = i+1; j < n+1; j++){
            for(int k = j+1; k < n+1; k++){
                if(arr[i][j] == 1 && arr[j][k] == 1 && arr[k][i] == 1){
                    ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
                }
            }
        }
    }
    
    if(ans == INT_MAX) return -1;
    return ans;
}