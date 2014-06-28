class Solution {
public:
// solution 1: greedy
    bool isMatch(const char *s, const char *p) {
        if (!s && !p) {
            return true;
        }
        const char *starS = NULL, *starP = NULL;
        while (*s != '\0') {
            if (*p == '*') {
                while (*p == '*') {
                    p++;
                }
                if (*p == '\0') {
                    return true;
                }
                starS = s;
                starP = p;
            } else if (*p == *s || *p == '?') {
                p++;
                s++;
            } else if (starS) {
                s = ++starS;
                p = starP;
            } else {
                return false;
            }
        }
        while (*p == '*') {
            p++;
        }
        return *p == '\0';
    }

// solution 2, recursive
    bool isMatch_2(const char *s, const char *p) {
        if (*p == '*') {
            while (*p == '*') {
                p++;
            }
            if (*p == '\0') {
                return true;
            }
            while (*s != '\0' && !isMatch(s, p)) {
                s++;
            }
            return *s != '\0';
        } else if (*p == '\0' || *s == '\0') {
            return *p == *s;
        } else if (*p == *s || *p == '?') {
            return isMatch(++s, ++p);
        } else {
            return false;
        }
    }
    
};
