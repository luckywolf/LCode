
class Solution {
public:
// DP, f(i) = \sum_{j=0}^i-1 f(j) * f(i-j-1), f(0) = 1, f(1) = 1;
    int numTrees(int n) {
        int count[n+1];
        count[0] = 1;
        for (int i = 1; i <= n; i++) {
            count[i] = 0;
            for (int j = 0; j < i; ++j) {
                count[i] += count[j] * count[i-j-1];
            }
        }
        return count[n];
    }
};
