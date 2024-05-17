

#include<bits/stdc++.h>

void getUniqueSubsets(vector<int>&arr, vector<int>&subset, int startingIndex, set<vector<int>>&uniqueSets){
    uniqueSets.insert(subset);

    for(int i = startingIndex; i < arr.size(); i++){
        subset.push_back(arr[i]);
        getUniqueSubsets(arr, subset, i+1, uniqueSets);
        subset.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    // Write Your Code Here   
    vector<vector<int>> ans;
    if(arr.size() == 0) return ans;

    vector<int> subset;
    set<vector<int>> uniqueSets;
    int startingIndex = 0;

    getUniqueSubsets(arr, subset, startingIndex, uniqueSets);

    for(auto uniqueSet : uniqueSets) ans.push_back(uniqueSet);

    return ans;
}