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
