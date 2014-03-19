class Solution {
public:
// dp. max profit =  max { frontProfit[0...i] + backProfit[i...N-1] }.
//                         0 <= i <= N-1
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> frontProfit(n, 0); 
        vector<int> backProfit(n, 0);
        int imin = 0, maxProfit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] < prices[imin]) {
                imin = i;
            }
            maxProfit = max(maxProfit, prices[i] - prices[imin]);
            frontProfit[i] = maxProfit; //maxProfit between [0, i]
        }
        
        maxProfit = 0;
        int imax = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (prices[i] > prices[imax]) {
                imax = i;
            }
            maxProfit = max(maxProfit, prices[imax] - prices[i]);
            backProfit[i] = maxProfit; //maxProfit between [i, n-1]
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, frontProfit[i] + backProfit[i]);
        }
        return res;
        
    }
};
