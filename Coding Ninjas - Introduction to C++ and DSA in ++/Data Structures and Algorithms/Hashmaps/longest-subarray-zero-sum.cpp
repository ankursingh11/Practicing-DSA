

#include<bits/stdc++.h>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here

    for(int i = 1; i < n; i++) arr[i] += arr[i-1];

    unordered_map<int, int> mp;
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            if( maxLength < i+1) maxLength=i+1;
        }else if(mp.count(arr[i]) > 0){
            if(maxLength < i - mp[arr[i]]) maxLength = i - mp[arr[i]];
        }else mp[arr[i]] = i;
    }

    return maxLength;
}