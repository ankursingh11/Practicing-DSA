
// https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

class Solution{
	public:
	int maxSumIS(int arr[], int n){
	    
	    vector<int> dp(n);
	    for(int i = 0; i < n; i++) dp[i] = arr[i];
	    
	    for(int i = n-1; i >= 0; i--){
	        for(int j = i+1; j < n; j++){
	            if(arr[i] < arr[j]){
	                dp[i] = max(dp[i], dp[j] + arr[i]);
	            }
	        }
	    }
	    
	    return *max_element(dp.begin(), dp.end());
	}
};