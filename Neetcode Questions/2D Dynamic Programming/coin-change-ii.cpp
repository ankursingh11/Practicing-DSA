
// https://leetcode.com/problems/coin-change-ii/

#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;

    void solve(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
        if (i >= coins.size()) return;

        if (amount == 0) {
            ans++;
            return;
        }

        if (dp[i][amount] != -1) {
            ans += dp[i][amount];
            return;
        }

        int countBefore = ans;

        if (coins[i] <= amount) {
            solve(amount - coins[i], coins, i, dp);
        }
        solve(amount, coins, i + 1, dp);

        dp[i][amount] = ans - countBefore;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int i = 0;
        solve(amount, coins, i, dp);
        return ans;
    }
};
