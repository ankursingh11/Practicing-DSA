
// https://leetcode.com/problems/happy-number/description/

/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    
    let slow = n;
    let fast = n;

    var findSquare = function(n){
        let ans = 0;
        while(n !== 0){
            let lastDigit = n%10;
            n = Math.floor(n/10);
            ans += Math.pow(lastDigit, 2)
        }
        return ans;
    }

    slow = findSquare(slow);
    fast = findSquare(findSquare(fast));

    while(slow !== fast){
        slow = findSquare(slow);
        fast = findSquare(findSquare(fast));
    }

    if(slow === 1) return true;
    return false;
};