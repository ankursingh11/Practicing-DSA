

int countZeros(int n) {
    // Write your code here
    if(n == 0) return 0;
    int a = n%10;
    int ans = countZeros(n/10);
    if(a == 0) return ans+1;
    else return ans;
}
