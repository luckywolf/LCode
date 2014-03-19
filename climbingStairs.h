class Solution {
public:
// DP, space O(n)  
// transition function: 
// f(n) = f(n-1) + f(n-2)  n>2;
//     or = 1   n=1
//     or = 2   n=2
    int climbStairs_1(int n) {
        if (n < 1) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            int dp[n];
            dp[0] = 1;
            dp[1] = 2;
            for (int i = 2; i < n; i++) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n-1];
        }
    }

// DP, space O(1)
    int climbStairs(int n) {
        int last = 1, lastlast = 1;
        for (int i = 2; i <= n; ++i) {
            int step = last + lastlast;
            lastlast = last;
            last = step;
        }
        return last;
    }
    
};
