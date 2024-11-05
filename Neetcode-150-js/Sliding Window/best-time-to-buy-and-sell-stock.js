
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let currMin = Number.MAX_SAFE_INTEGER;
    let profit = Number.MIN_SAFE_INTEGER;

    for(let price of prices){
        currMin = Math.min(currMin, price);
        profit = Math.max(profit, price - currMin);
    }

    return profit;
};