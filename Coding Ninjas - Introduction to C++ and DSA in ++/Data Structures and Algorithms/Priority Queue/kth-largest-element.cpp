

#include<bits/stdc++.h>

int kthLargest(vector<int>&arr, int k) {
    // Write your code here

    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k-1];
}