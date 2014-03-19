class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int k = max(m, n);
        string res(k, ' ');
        m = m - 1, n = n - 1, k = k - 1;
        int carry = 0;
        while (k >= 0) {
            int sum = carry;
            if (m >= 0) {
                sum += a[m--] - '0';
            }
            if (n >= 0) {
                sum += b[n--] - '0';
            }
            carry = sum / 2;
            sum %= 2;
            res[k--] = sum + '0';
        }
        if (carry == 1) {
            res.insert(res.begin(), '1');
        }
        return res;
    }
};
