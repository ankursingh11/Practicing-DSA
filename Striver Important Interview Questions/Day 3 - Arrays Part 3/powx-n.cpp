
// https://leetcode.com/problems/powx-n/

class Solution {
public:

    double solve1(double x, int n){
        if(n == 0) return 1;
        double ans = solve1(x, n/2);
        if(n%2 == 0) return ans*ans;
        return x*ans*ans;
    }

    double solve2(double x, int n){
        if(n == 0) return 1;
        double ans = solve2(x, n/2);
        if(n%2 == 0) return ans*ans;
        return (1/x)*ans*ans;
    }

    double myPow(double x, int n) {
        if(n == 0) return 1; 
        if(n < 0) return solve2(x, n);
        return solve1(x, n);
    }
};