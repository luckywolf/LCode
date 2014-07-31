class Solution {
public:
// Dynamic programming. UP(i,j) = UP(i-1,j) + UP(i,j-1).
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    // second round
    int uniquePaths(int m, int n) {
      assert(m >= 0 && n >= 0);
      if (m == 0 || n == 0) {
          return 0;
      }
      vector<int> dp(n, 1);
      for (int i = 1; i < m; ++i) {
          for (int j = 1; j < n; ++j) {
              dp[j] += dp[j-1];
          }
      }
      return dp[n-1];
    }    
};
