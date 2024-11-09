
// https://leetcode.com/problems/powx-n/

class Solution {
  
  solve1(x, n) {
    if (n === 0) return 1;
    let ans = this.solve1(x, Math.floor(n / 2));
    if (n % 2 === 0) return ans * ans;
    return x * ans * ans;
  }

  solve2(x, n) {
    if (n === 0) return 1;
    let ans = this.solve2(x, Math.floor(n / 2));
    if (n % 2 === 0) return ans * ans;
    return (1 / x) * ans * ans;
  }

  myPow(x, n) {
    if (n === 0) return 1;
    if (n < 0) return this.solve2(x, n);
    return this.solve1(x, n);
  }
}