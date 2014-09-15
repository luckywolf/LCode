/*
https://oj.leetcode.com/problems/interleaving-string/

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/
class Solution {
public:
// first try, recursion, TLE
    bool isInterleave_1(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) {
            return false;
        }
        return isInterleaveRe_1(s1, m, 0, s2, n, 0, s3, k, 0);
    }
    
    bool isInterleaveRe_1(string s1, int len1, int pos1, 
                        string s2, int len2, int pos2,
                        string s3, int len3, int pos3) {
                            
        if (pos3 == len3) {
            return true;
        }
        bool res = false;
        if (pos1 < len1) {
            res |= (s1[pos1++] == s3[pos3++]) && isInterleaveRe_1(s1, len1, pos1--, 
                                                           s2, len2, pos2, s3, len3, pos3--);
        }
        if (pos2 < len2) {
            res |= (s1[pos1++] == s3[pos3++]) && isInterleaveRe_1(s1, len1, pos1, 
                                                           s2, len2, pos2--, s3, len3, pos3--);
        }
        return res;
    }
// optimized, recursion, TLE  
    bool isInterleave_2(string s1, string s2, string s3) {
        return isInterleaveRe_2(s1.c_str(), s2.c_str(), s3.c_str());
    }
    
    bool isInterleaveRe_2(const char *s1, const char *s2, const char *s3) {
        if (*s1 == '\0' && *s2 == '\0' && s3 == '\0') {
            return true;
        }
        if (*s3 == '\0') {
            return false;
        }
        if (*s1 == '\0') {
            return strcmp(s2, s3) == 0;
        }
        if (*s2 == '\0') {
            return strcmp(s1, s3) == 0;
        }
        return *s1 == *s3 && isInterleaveRe_2(s1+1, s2, s3+1)
               || *s2 == *s3 && isInterleaveRe_2(s1, s2+1, s3+1);
    }
// dp, match from end to beginning of the string
// dp[i][j]: i chars from S1 is used, j chars from S2 is used
    bool isInterleave_3(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) {
            return false;
        }
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = (s1[m-i] == s3[m+n-i]) && dp[i-1][0];
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = (s2[n-j] == s3[m+n-j]) && dp[0][j-1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (s1[m-i] == s3[m+n-i-j]) && dp[i-1][j] ||
                           (s2[n-j] == s3[m+n-i-j]) && dp[i][j-1];
            }
        }
        return dp[m][n];
    }
    
// dp, match from beginning to the end of the string
// dp[i][j]: i chars from S1 is used, j chars from S2 is used 
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) {
            return false;
        }
        bool dp[m+1][n+1];
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = (s1[i-1] == s3[i-1]) && dp[i-1][0];
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = (s2[j-1] == s3[j-1]) && dp[0][j-1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = (s1[i-1] == s3[i+j-1]) && dp[i-1][j] ||
                           (s2[j-1] == s3[i+j-1]) && dp[i][j-1];
            }
        }
        return dp[m][n];
    }
   
};
