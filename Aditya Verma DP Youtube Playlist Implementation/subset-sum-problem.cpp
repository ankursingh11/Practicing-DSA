
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
        // creating a table and initialising it
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(i == 0) dp[i][j] = false;
                if(j == 0) dp[i][j] = true;
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};