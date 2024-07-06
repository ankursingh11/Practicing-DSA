
// https://leetcode.com/problems/happy-number/description/

class Solution {
public:

    int findSquare(int n){
        int ans = 0;
        while(n != 0){
            int lastDigit = n%10;
            ans += pow(lastDigit, 2);
            n = n/10;
        }

        return ans;
    }

    bool isHappy(int n) {
        
        int slow = n, fast = n;

        slow = findSquare(n);
        fast = findSquare(findSquare(n));

        while(slow != fast){
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));
        }

        if(slow == 1) return true;
        return false;
    }
};