/*
https://oj.leetcode.com/problems/implement-strstr/

Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/
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
    char *strStr_2(char *haystack, char *needle) {
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
    
    
    // KMP
    // http://chaoswork.com/blog/2011/06/14/kmp%E7%AE%97%E6%B3%95%E5%B0%8F%E7%BB%93/
    // http://n00tc0d3r.blogspot.com/2013/03/implement-strstr.html?view=flipcard
    void buildNextTable(char *pattern, int* next, int length) {  
        next[0] = -1;
        for (int i = 2; i <= length; ++i) {  
            int j = next[i-1];  
            while (j > -1 && pattern[i - 1] != pattern[j]) {
                j = next[j];
            }
            if (j > -1) {
                next[i] = j + 1;  
            }
        }
    }  
   
    char *strStr(char *haystack, char *needle)  {
        int n = strlen(haystack);
        int m = strlen(needle);
        if (m == 0) {
            return haystack; 
        }
        if (n < m) { 
            return NULL; 
        }
        int *next = new int[m + 1];
        // memset(myarray, 0, sizeof(myarray)); // for automatically-allocated arrays
        // memset(myarray, 0, N*sizeof(*myarray)); // for heap-allocated arrays, where N is the number of elements
        memset(next, 0, (m+1) * sizeof(next));
        buildNextTable(needle, next, m);  
        int offset = 0, start = 0;  
        while (offset < n) {  
            if (haystack[offset] == needle[start]) {  
                ++offset;  
                if (++start == m) {  
                    return haystack + offset;  
                }  
            } else if (start > 0) {  
                start = next[start];  
            } else {  
                ++offset;  
            }  
        }  
        return NULL;  
    }   
};
