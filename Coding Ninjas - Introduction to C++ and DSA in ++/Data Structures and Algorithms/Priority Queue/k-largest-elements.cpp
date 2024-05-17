

#include<bits/stdc++.h>

vector<int> kLargest(int input[], int n, int k){
    sort(input, input+n, greater<int>());
    vector<int> ans;
    for(int i = 0; i < k; i++) ans.push_back(input[i]);
    return ans;
}
