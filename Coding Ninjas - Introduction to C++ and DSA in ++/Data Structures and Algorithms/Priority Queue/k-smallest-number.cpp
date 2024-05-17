

#include<bits/stdc++.h>

vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here
    sort(input, input+n);
    vector<int> ans;
    for(int i = 0; i < k; i++) ans.push_back(input[i]);
    return ans;
}