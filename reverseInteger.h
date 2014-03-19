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
