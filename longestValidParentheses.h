class Solution {
public:
// DP, time O(n), space O(n)
    int longestValidParentheses_1(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        // or int dp[n]
        // memset(dp, 0, sizeof(dp));
        int longest = 0;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == '(') {
                int j = i + dp[i+1] + 1;
                if (j < n && s[j] == ')') {
                    dp[i] = dp[i+1] + 2;
                    if (j + 1 < n) {
                        dp[i] += dp[j+1];
                    }
                }
            }
            longest = max(longest, dp[i]);
        }
        return longest;
    }

// Use stack Time O(n), space O(n)  
    int longestValidParentheses(string s) {
        stack<int> stk;
        int leftBound = -1;
        int longest = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i); // cautious: push index i, not index i-1 
            } else if (stk.empty()) {
                leftBound = i;
            } else {
                stk.pop();
                int length = stk.empty() ? i - leftBound : i - stk.top();
                longest = max(longest, length);
            }
        }
        return longest;
    }
    
};
