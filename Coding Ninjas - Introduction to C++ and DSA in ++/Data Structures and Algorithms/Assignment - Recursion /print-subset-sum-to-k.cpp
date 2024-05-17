

#include<bits/stdc++.h>

void helper(int input[], int size, int k, vector<vector<int>>&ans, vector<int>&subset, int startingIndex){
    
    int currSum = accumulate(subset.begin(), subset.end(), 0);
    if(currSum == k){
        ans.push_back(subset);
    }

    for(int i = startingIndex; i < size; i++){
        subset.push_back(input[i]);
        helper(input, size, k, ans, subset, i+1);
        subset.pop_back();
    }
}


void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    if(size == 0) return;
    
    vector<vector<int>> ans;
    vector<int> subset;
    int startingIndex = 0;

    helper(input, size, k, ans, subset, startingIndex);
    
    for(auto smallAns : ans){
        for(auto ele : smallAns){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

    return;
}
