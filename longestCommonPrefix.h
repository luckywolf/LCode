/*
https://oj.leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
// first try; 
    string longestCommonPrefix_1(vector<string> &strs) {
        string res;
        if (strs.empty()) {
            return res;
        }
        int n = strs.size();
        int cur = 0, i = 0;
        while (true) {
            for (i = 0; i < n; ++i) {
                if (cur == strs[i].size() || (i > 0 && strs[i][cur] != strs[i-1][cur])) {
                    break;
                }
            }
            if (i == n) {
                cur++;
            } else {
                break;
            }
        }
        if (cur == 0) {
            return res;
        } else {
            return strs[0].substr(0, cur);
        }
    }
// optimized
    string longestCommonPrefix_2(vector<string> &strs) {
        string res;
        if (strs.empty()) {
            return res;
        }
        for (int i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || strs[j][i] != ch) {
                    return res;
                }
            }
            res.push_back(ch);
        }
        return res;
    }
    
// optimized 2
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        for (int i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || strs[j][i] != ch) {
                    int rightMost = i - 1;
                    return strs[0].substr(0, rightMost + 1);
                }
            }
        }
        return strs[0];
    }    
};
