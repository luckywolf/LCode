/*
https://oj.leetcode.com/problems/triangle/

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
public:
// dp, time O(n^2), space O(n), top-down
    int minimumTotal_1(vector<vector<int> > &triangle) {
        int n = triangle.size();
        int dp[n];
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + triangle[i][i];
            for (int j = i-1; j > 0; --j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j-1]);
            }
            dp[0] += triangle[i][0];
        }
        int res = dp[0];
        for (int i = 1; i < n; ++i) {
            if (dp[i] < res) {
                res = dp[i];
            }
        }
        return res;
    }
    
    // dp, time O(n^2), space O(n), buttom-up
    int minimumTotal_2(vector<vector<int> > &triangle) {
        int n = triangle.size();
        int dp[n];
        for (int i = 0; i < n; ++i) {
            dp[i] = triangle[n-1][i];
        }
        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }

// dp, time O(n^2), space O(1) but change parameter, bottom-up
    int minimumTotal_3(vector<vector<int> > &triangle) {
        for (int i = triangle.size() - 2; i >= 0 ; --i) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }

};
