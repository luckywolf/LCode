/*
https://oj.leetcode.com/problems/powx-n/

Implement pow(x, n).
*/
class Solution {
public:
// recursive, O(lgn)
    double pow_1(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double half = pow(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else if (n > 0) {
            return half * half * x;
        } else {
            return half * half / x;
        }
    }
    
// recursive, O(lgn)
    double pow(double x, int n) {
        if (n < 0) {
            return 1.0 / powRe(x, -n);
        } else {
            return powRe(x, n);
        }
    }
    
    double powRe(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        double half = pow(x, n/2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }    
    
// iterative, O(lgn)
    double pow_3(double x, int n) {
        unsigned int m = abs(n);
        double res = 1.0;
        for (; m; x *= x, m >>= 1) {
            if (m & 0x1) {
                res *= x; 
            }
        }
        return (n < 0) ? (1.0 / res) : res;
    }
};
