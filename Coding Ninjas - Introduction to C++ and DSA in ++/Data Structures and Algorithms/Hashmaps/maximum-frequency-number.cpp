

#include<bits/stdc++.h>

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) mp[arr[i]]++;

    int ans = arr[0], ansCount = mp[arr[0]];
    for(auto it : mp){
        if(it.second > ansCount){
            ans = it.first;
            ansCount = it.second;
        }
    }

    return ans;
}