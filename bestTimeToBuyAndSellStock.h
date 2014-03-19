class Solution {
public:
// soluiton 1, record minimum value
    int maxProfit_1(vector<int> &prices) {
        int min = INT_MAX, res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            res = max(res, prices[i] - min);
        }
        return res;
    }

// solution 2, record minmum index
    int maxProfit(vector<int> &prices) {
        int imin = 0, res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < prices[imin]) {
                imin = i;
            }
            res = max(res, prices[i] - prices[imin]);
        }
        return res;
    }
    
};
