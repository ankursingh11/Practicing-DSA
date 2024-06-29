
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int weight[], int value[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
       
       for(int i = 1; i < n+1; i++){
           for(int j = 1; j < W+1; j++){
               if(weight[i-1] <= j){
                   dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
               }else dp[i][j] = dp[i-1][j];
           }
       }
       
       return dp[n][W];
       
    }
};