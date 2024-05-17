

#include<bits/stdc++.h>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>> roads) {
    
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<int> degree(n, 0);
    
    for(auto road : roads){
        int x = road[0];
        int y = road[1];
        degree[x]++;
        degree[y]++;
        arr[x][y]++;
        arr[y][x]++;
    }
    
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ans = max(ans, degree[i] + degree[j] - arr[i][j]);
        }
    }
    
    return ans;
}