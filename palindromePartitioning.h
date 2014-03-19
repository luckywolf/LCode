class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<bool> temp(n, false);
        vector<vector<bool>> dp(n, temp);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int start = i, end = j;
                while (start < end) {
                    if (s[start] != s[end]) {
                        break;
                    }
                    start++;
                    end--;
                }
                if (start >= end) {
                    dp[i][j] = true;
                }
            }
        }
        vector<string> output;
        vector<vector<string>> res;
        partitionRe(s, 0, dp, output, res);
        return res;
    }
    
    void partitionRe(string s, int start, vector<vector<bool>> &dp,
                     vector<string> &output, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            output.push_back(s.substr(start, i - start + 1));
            if (dp[start][i]) {
                partitionRe(s, i+1, dp, output, result);
            }
            output.pop_back();
        }
    }
};
