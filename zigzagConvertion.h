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
