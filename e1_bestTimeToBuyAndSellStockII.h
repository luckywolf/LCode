/*
https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
public:
// For ascending order [1,2,4], (4 - 1) == (2 - 1) + (4 - 2).
    int maxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int profit  = prices[i] - prices[i-1];
            if (profit > 0) {
                res += profit;
            }
        }
        return res;
    }
};
