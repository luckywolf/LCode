class Solution {
public:
// the result is at most m+n long. e.g 99 * 99 < 10,000
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res(m+n, '0');
        for (int i = m-1; i >= 0; --i) {
            int carry = 0;
            for (int j = n-1; j >= 0; --j) {
                int sum = carry + (res[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0');
                carry = sum / 10;
                res[i+j+1] = sum % 10 + '0';
            }
            res[i] += carry;
        }
        
        while (res.size() > 1 && res[0] == '0') {
            res.erase(res.begin());
        }
        return res;
    }
};
