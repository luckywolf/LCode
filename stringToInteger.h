class Solution {
public:
//use long long
    int atoi_1(const char *str) {
        long long res = 0;
        if (!str) {
            return res;
        }
        while (*str == ' ') {
            str++;
        }
        bool positive = true;
        if (*str == '+') {
            str++;
        } else if (*str == '-') {
            str++;
            positive = false;
        }
        while (isdigit(*str)) {
            res = res * 10 + *str - '0';
            str++;
        }
        if (!positive) {
            res = -res;
        }
        if (res > INT_MAX) {
            return INT_MAX;
        } 
        if (res < INT_MIN) {
            return INT_MIN;
        }
        return res;
    }
// use int 
 int atoi(const char *str) {
        int res = 0;
        if (!str) {
            return res;
        }
        while (*str == ' ') {
            str++;
        }
        bool positive = true;
        if (*str == '+') {
            str++;
        } else if (*str == '-') {
            str++;
            positive = false;
        }
        while (isdigit(*str)) {
            if (INT_MAX / 10 < res || INT_MAX / 10 == res && INT_MAX % 10 < *str - '0') {
                return positive ? INT_MAX : INT_MIN;
            }
            res = res * 10 + *str - '0';
            str++;
        }
        return positive ? res : -res;
    }

};
