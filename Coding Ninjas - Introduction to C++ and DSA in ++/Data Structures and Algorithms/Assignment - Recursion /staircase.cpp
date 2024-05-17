
int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n<=2) return n;
    if(n == 3) return 4;
    
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4; i <= n; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    return dp[n];
}