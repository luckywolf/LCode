/*
https://oj.leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, determine if s can be segmented into 
a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
// DP, O(n) space, O(n^2) time, n is the lenght of s
// check[i]: if the sub string before s[i] (s[0], ... , s[i-1]) can be broken
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> check(n+1, false);
        check[0] = true;
        for (int i = 0; i < n; ++i) {
            if (check[i]) {
                for (int j = 1; j <= n-i; ++j) {
                    if (dict.find(s.substr(i, j)) != dict.end()) {
                        check[i+j] = true;
                    }
                }
            }
        }
        return check[n];
    }

// DP, O(n^2) space, O(n^2) time, n is the lenght of s 
    bool wordBreak_1(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<vector<bool>> check(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dict.find(s.substr(i, j-i+1)) != dict.end()) {
                    check[i][j] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!check[0][i]) {
                for (int j = 0; j < i; ++j) {
                    if (check[0][j] && check[j+1][i]) {
                        check[0][i] = true;
                        break;
                    }
                }
            }
        }
        return check[0][n-1];
    }
    
    bool wordBreak_2(string s, unordered_set<string> &dict) {
        string s2 = "#" + s;
        int n = s2.size();
        vector<bool> canBreak(n, false);
        canBreak[0] = true;
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < i; k++) {
                canBreak[i] = canBreak[k] && dict.find(s2.substr(k+1, i-k)) != dict.end();
                if (canBreak[i]) {
                    break;
                }
            }
        }
        return canBreak[n-1];
    }    
    
};
