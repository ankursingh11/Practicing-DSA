

#include<bits/stdc++.h>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here

    unordered_map<int, int> mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int complement = arr[i] + k;
        ans += mp[complement];

        if(k != 0){
            complement = arr[i]-k;
            ans += mp[complement];
        }

        mp[arr[i]]++;
    }

    return ans;
}