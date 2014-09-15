/*
https://oj.leetcode.com/problems/divide-two-integers/

Divide two integers without using multiplication, division and mod operator.
*/
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
    
    // second round
    int divide_3(int dividend, int divisor) {
        assert(divisor != 0);
        if (dividend == 0) {
            return 0;
        }
        bool positive = dividend > 0 && divisor > 0 ||
                    dividend < 0 && divisor < 0;
        long long divdll = abs((long long)dividend);
        long long divsll = abs((long long)divisor);
        int res = 0;
        while (divdll >= divsll) {
            unsigned int temp = 1;
            long long tempdivs = divsll;
            while ((tempdivs << 1) <= divdll) {
                tempdivs <<= 1;
                temp <<= 1;
            }
            res += temp;
            divdll -= tempdivs;
        // code is cleaner with some performance penalty
            // while(divdll >= divsll)) {
            //     tempdivs >>= 1;
            //     temp >>= 1;
            //     if (divdll >= adivsll) {
            //         res += temp;
            //         adivd -= adivs;
            //     }
            // }
        }
        return positive ? res: -res;
    }
    
    // rewrite
    int divide_4(int dividend, int divisor) {
        assert(divisor != 0);
        if (dividend == 0) {
            return 0;
        }
        bool positive = dividend > 0 && divisor > 0 ||
                    dividend < 0 && divisor < 0;
        unsigned int divd = abs(dividend);
        unsigned int divs = abs(divisor);
        int res = 0;
        if (divd >= divs) {
            int temp = 1;
            unsigned int tempdivs = divs;
            while ( (tempdivs << 1) > 0 && (tempdivs << 1) <= divd) {
                tempdivs <<= 1;
                temp <<= 1;
            }
            res += temp;
            divd -= tempdivs;
            while(divd >= divs) {
                tempdivs >>= 1;
                temp >>= 1;
                if (divd >= tempdivs) {
                    res += temp;
                    divd -= tempdivs;
                }
            }
        }
        return positive ? res: -res;
    }
    
    // rewrite
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if (dividend  == 0) {
            return 0;
        }
        bool flag = dividend > 0 && divisor > 0 ||
                    dividend < 0 && divisor < 0;
        unsigned int divd = abs(dividend);
        unsigned int divs = abs(divisor);
        int temp[32] = {0};
        int res = 0;
        int i = 0;
        while (divs > 0 && divs <= divd) {
            temp[i] = divs;
            divs <<= 1;
            i++;
        }
        i--;
        while (i >= 0) {
            if (divd >= temp[i]) {
                res += 1 << i;
                divd -= temp[i];
            }
            i--;
        }
        return flag ? res : -res;
    }
        
    
};
