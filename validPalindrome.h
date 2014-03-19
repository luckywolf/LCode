#include <cctype>

class Solution {
public:
    // first try
    bool isPalindrome_1(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            } else {
                l++;
                r--;
            }
        }
        return true;
    }
    
    // optimized
    bool isPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
        }
        return true;
    }
};
