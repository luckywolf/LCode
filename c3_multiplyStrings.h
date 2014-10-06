/*
https://oj.leetcode.com/problems/multiply-strings/

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
class Solution {
public:
// the result is at most m+n long. e.g 99 * 99 < 10,000
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        string res(m+n, '0');
        for (int i = m-1; i >= 0; --i) {
            int carry = 0; // be cautious
            for (int j = n-1; j >= 0; --j) {
                // be cautious
                int sum = carry + (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                carry = sum / 10;
                res[i+j+1] = sum % 10 + '0';
            }
            res[i] += carry; // be cautious
        }
        // the commented code also works
        // while (res.size() > 1 && res[0] == '0') {
            // res.erase(res.begin());
        // }
        // return res;
        int k = 0;
        for (; k < m+n; ++k) {
            if (res[k] != '0')  {
                break;
            }
        }
        return res.substr(k, m+n-k);
    }
};
