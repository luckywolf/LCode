/*
https://oj.leetcode.com/problems/edit-distance/

Given two words word1 and word2, find the minimum number of steps 
required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
class Solution {
public:
// dp, time O(mn), space O(mn)
// dp[i][j]: edit distance from word1.substr(0,i) to word2.substr(0,j)
    int minDistance_1(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m+1][n+1];
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // be cautious, min only takes two parameters
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                }
            }
        }
        return dp[m][n];
    }
 
// dp, time O(mn), space O(n)
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[n+1];
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }
        for (int i = 1; i <= m; ++i) {
            int upperLeftBackup = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; ++j) {
                int upperLeft = upperLeftBackup;
                upperLeftBackup = dp[j];
                if (word1[i-1] == word2[j-1]) {
                    dp[j] = upperLeft;
                } else {
                    dp[j] = 1 + min(upperLeft, min(dp[j], dp[j-1]));
                }
            }
        }
        return dp[n];
    }
    
    
};
