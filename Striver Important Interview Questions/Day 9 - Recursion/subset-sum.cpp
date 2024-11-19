
// https://www.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
  public:

    void solve(vector<int>&arr, int n, vector<int>&ans, vector<int>&subset, int si){
        
        int curr_subset_sum = accumulate(subset.begin(), subset.end(), 0);
        ans.push_back(curr_subset_sum);
        
        for(int i = si; i < n; i++){
            subset.push_back(arr[i]);
            solve(arr, n, ans, subset, i+1);
            subset.pop_back();
        }
    }
  
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        if(n == 0) return ans;
        
        vector<int> subset;
        solve(arr, n, ans, subset, 0);
        return ans;
    }
};