/*
https://oj.leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
*/
class Solution {
public:
// Space O(1), Time O(n^2)
    string longestPalindrome_1(string s) {
        int n =  s.size();
        int first = 0, second = 0; // s[0], the first center in the possible 2n-1 centers
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) { // check all 2n-1 centers
                int start = i, end = i+j;
                if (s[start] == s[end]) {
                    while (start > 0 && end < n - 1) {
                        if (s[--start] != s[++end]) {
                            start++;
                            end--;
                            break;
                            }
                        }
                    if (end - start > second - first) {
                        second = end;
                        first = start;
                    }
                }
            }
        }
        return s.substr(first, second - first + 1);
    }

// Space O(n^2); Time O(n^2), but is better than the above algorithm
    string longestPalindrome_2(string s) {
        int n =  s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        int start = 0, end = 0; // s[0]
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = n-2; i >= 0 ; --i) {
            for (int j = i+1; j < n; ++j) {
                dp[i][j] = (j - i <= 2 || dp[i+1][j-1]) && s[i] == s[j];
                if (dp[i][j] && j - i > end - start) {
                    end = j;
                    start = i;
                }
            }
        }
        return s.substr(start, end - start + 1); 
    }
};
