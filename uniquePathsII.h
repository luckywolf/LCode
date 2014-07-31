class Solution {
public:
// Dynamic programming UP(i,j) = UP(i-1, j) + UP(i, j-1)
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    
    // second round 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        assert(m > 0);
        int n = obstacleGrid[0].size();
        assert(n > 0);
        vector<int> dp(n, 0);
        dp[0] = obstacleGrid[0][0] == 1 ? 0: 1;
        for (int i = 1; i < n; ++i) {
            dp[i] = obstacleGrid[0][i] == 1 ? 0: dp[i-1];
        }
        for (int i = 1; i < m; ++i) {
            dp[0] = obstacleGrid[i][0] == 1 ? 0: dp[0];
            for (int j = 1; j < n; ++j) {
                dp[j] = obstacleGrid[i][j] == 1 ? 0 : dp[j] + dp[j-1]; 
            }
        }
        return dp[n-1];
    }    
};
