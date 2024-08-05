
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = INT_MAX;
        int maxProfit = INT_MIN;
        for(auto price : prices){
            currMin = min(currMin, price);
            maxProfit = max(maxProfit, price-currMin);
        }
        return maxProfit;
    }
};