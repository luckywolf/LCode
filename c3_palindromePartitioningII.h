/*
https://oj.leetcode.com/problems/palindrome-partitioning-ii/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
// DP
// isP[i][j] = s[i] == s[j] && (j-i < 2 || isP[i+1][j-1]
// minCut[i] = min(1 + minCut[j+1]) ( i <= j < n)
// minCut means the minimum cut for string s.substr(i, n-i), or s[i]... s[n-1]
    int minCut(string s) {
        int n = s.size();
        int minCut[n];
        for (int i = 0; i < n; ++i) {
            minCut[i] = n-1-i;
        }
        bool isP[n][n];
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                isP[i][j] = false;
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j-i < 2 || isP[i+1][j-1])) {
                    isP[i][j] = true;
                    minCut[i] = min(minCut[i], minCut[j+1]+1);
                }
            }
        }
        return minCut[0];
    }
// backtracking    
    int minCut_2(string s) {
        int n = s.size();
        vector<bool> temp(n, false);
        vector<vector<bool>> isP(n, temp);
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j-i < 2 || isP[i+1][j-1])) {
                    isP[i][j] = true;
                }
            }
        }
        int minCut = n-1;
        dfs(s, isP, 0, 0, minCut);
        return minCut;
    }
    
    void dfs(string &s, vector<vector<bool>> bp, int start, int cut, int &minCut) {
        if (start == s.size()) {
            if (cut < minCut) {
                minCut = cut;
            }
            return;
        }
        if (cut >= minCut) {
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (bp[start][i]) {
                dfs(s, bp, i+1, cut+1, minCut);
            }
        }
    }
};
