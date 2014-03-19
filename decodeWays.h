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

// DP
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
