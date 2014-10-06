/*
https://oj.leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, 
then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? 
You would then have to re-design the function (ie, add an extra parameter).
*/
class Solution {
public:
// first try
    int reverse_1(int x) {
        int res = 0;
        bool positive =  true;
        if (x < 0) {
            positive = false;
            x = 0 - x;
        }
        while (x > 0) {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return positive ? res : 0 - res;
    }
    
// use long long and assert to handle overflow, and don't need to handle negative seperately
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        assert (x >= INT_MIN && x <= INT_MAX);
        return res;
    }
};
