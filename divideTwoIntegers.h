class Solution {
public:
// use long long and <<
    int divide_1(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        bool flag = dividend > 0 && divisor > 0 ||
                    dividend < 0 && divisor < 0;
        long long divdll = abs((long long)dividend);
        long long divsll = abs((long long)divisor);
        int res = 0;
        while (divdll >= divsll) {
            unsigned int i = 1;
            long long divs = divsll;
            while ((divs << 1) <= divdll) {
                divs <<= 1;
                i <<= 1;
            }
            res += i;
            divdll -= divs;
        }
        return flag ? res : - res;
    }

// use unsigned int and extra space
    int divide(int dividend, int divisor) {
        if (dividend  == 0) {
            return 0;
        }
        bool flag = dividend > 0 && divisor > 0 ||
                    dividend < 0 && divisor < 0;
        unsigned int divd = abs(dividend);
        unsigned int divs = abs(divisor);
        int inc[32];
        int res = 0;
        int i = 0;
        for (; divs > 0 && divs <= divd; ++i) {
            inc[i] = divs;
            divs <<= 1;
        }
        i--;
        while (i >= 0 && divd > 0) {
            if (divd >= inc[i]) {
                res += 1 << i;
                divd -= inc[i];
            }
            i--;
        }
        return flag ? res : -res;
    }
    
};
