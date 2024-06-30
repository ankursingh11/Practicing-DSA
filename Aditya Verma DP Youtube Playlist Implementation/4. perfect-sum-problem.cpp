
// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int mod = 1e9+7;
        
        if(n == 0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%mod;
                }else dp[i][j] = (dp[i-1][j])%mod;
            }
        }
        
     return dp[n][sum]%mod;   
	}
};