/*
https://oj.leetcode.com/problems/palindrome-number/

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
class Solution {
public:
// iterative
    bool isPalindrome_1(int x) {
        if (x < 0) {
            return false;
        }
        int div = 10;
        while (x / div >= 10){
            div *= 10;
        }
        while (x >= 10) {
            if (x / div != x % 10) {
                return false;
            }
            x %= div;
            x /= 10;
            div /= 100;
        }
        return true;
    }

//recursive
    bool isPalindrome(int x, int &y) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        if (isPalindrome(x / 10, y) && (x % 10 == y % 10)) {
            y /= 10;
            return true;
        } else {
            return false;
        }
    }
    
    bool isPalindrome(int x) {
        return isPalindrome(x, x);
    }
};
