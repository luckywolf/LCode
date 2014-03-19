class Solution {
public:
    // first try
    char *strStr_1(char *haystack, char *needle) {
        if (needle == NULL || *needle == '\0') {
            return haystack;
        }
        
        char *pCur = haystack;
        char *pAdv = haystack;
        char *pNeedle = needle;
        while (*++pNeedle != '\0') {
            if (*pAdv == '\0') {
                return NULL;
            } else {
                pAdv++;
            }
        }
        
        while (*pAdv != '\0') {
            pNeedle = needle;
            char *p1 = pCur;
            while (*pNeedle != '\0' && *p1 != '\0' && *p1 == *pNeedle) {
                    p1++;
                    pNeedle++;
            }
            if (*pNeedle == '\0') {
                return pCur;
            } else {
                pCur++;
                pAdv++;
            }
        }
        return NULL;
    }
    
    // optimized and without the advanced pointer
    char *strStr(char *haystack, char *needle) {
        while (haystack != '\0') {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *h == *n) {
                h++;
                n++;
                }
            if (*n == '\0') {
                return haystack;
            }
            if (*h == '\0') {
                return NULL;
            }
            haystack++;
        }
        return NULL;
    }
};
