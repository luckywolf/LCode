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
