
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let currMin = Number.MAX_SAFE_INTEGER;
    let maxProfit = Number.MIN_SAFE_INTEGER;
    
    for(const price of prices){
        currMin = Math.min(currMin, price);
        maxProfit = Math.max(maxProfit, price - currMin);
    }

    return maxProfit;
};