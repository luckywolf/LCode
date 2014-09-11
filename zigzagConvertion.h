/*
https://oj.leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        string res;
        if (s.empty()) {
            return res;
        }
        int inc = 2 * (nRows - 1);
        int n = s.size();
        for (int row = 0; row < nRows; ++row) {
            for (int col = 0, index = row; index < n; col++, index = inc * col + row) {
                res.push_back(s[index]);
                if (row == 0 || row == nRows -1) {
                    continue;
                }
                if (index + inc - 2 * row < n) {
                    res.push_back(s[index + inc - 2 * row]);
                }
            }
        }
        return res;
    }
};
