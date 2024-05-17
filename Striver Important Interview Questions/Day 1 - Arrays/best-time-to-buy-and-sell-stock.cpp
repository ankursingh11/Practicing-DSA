
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX, profit = INT_MIN;
        for(auto price : prices){
            currMin = min(currMin, price);
            profit = max(profit, price - currMin);
        }

        return profit;
    }
};