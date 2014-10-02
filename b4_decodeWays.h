/*
https://oj.leetcode.com/problems/decode-ways/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/
class Solution {
public:
// Brute force
    int numDecodings_1(string s) {
        int res = 0;
        if (!s.empty()) {
            numDecodingsRe(s, res);
        }
        return res;
    }
    
    void numDecodingsRe(string s, int &res) {
        if (s.size() == 0) {
            res++;
            return;
        }
        if (s[0] == '0') {
            return;
        }
        numDecodingsRe(s.substr(1, s.size() - 1), res);
        if (s.size() > 1) {
            int temp = (s[0] - '0') * 10 + s[1] - '0';
            if (temp <= 26) {
                numDecodingsRe(s.substr(2, s.size() - 2), res);
            }
        }
    }

// optimized brute force
    int numDecodings_2(string s) {
        int res = 0;
        if (!s.empty()) {
            numDecodingsRe_2(s, 0, res);
        }
        return res;
    }
    
    void numDecodingsRe_@(string &s, int start, int &res) {
        if (start == s.size()) {
            res++;
            return;
        }
        if (s[0] == '0') {
            return;
        }
        numDecodingsRe_2(s, start+1, res);
        if (start < s.size()-1) {
            int temp = (s[start] - '0') * 10 + s[start+1] - '0';
            if (temp <= 26) {
                numDecodingsRe_2(s, start+2, res);
            }
        }
    }

// DP, dp[i]: number of Decodings for substring starting from s[i]
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n+2, 0);
        dp[n] = 1;
        for (int i = n-1; i >=0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i+1];
                if (s.size() > 1 && (s[i] - '0') * 10 + (s[i+1] - '0') <= 26) {
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
    
};
