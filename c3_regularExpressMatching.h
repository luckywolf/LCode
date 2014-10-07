/*
https://oj.leetcode.com/problems/regular-expression-matching/

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "a*") -> true
isMatch("aa", ".*") -> true
isMatch("ab", ".*") -> true
isMatch("aab", "c*a*b") -> true
*/
class Solution {
public:

// recursive
// http://leetcode.com/2011/09/regular-expression-matching.html
    bool isMatch_1(const char *s, const char *p) {
        if (*p == '\0') {
            return  *s == '\0';
        }
        if (*(p+1) == '*') {
            while ((*p == *s || *p == '.') && *s != '\0') {
                if (isMatch_1(s, p+2)) {
                    return true;
                }
                s++;
            }
            return isMatch_1(s, p+2);
        }
        
        if (*s == '\0') {
            return false;
        }
        return (*p == *s || *p == '.') && isMatch_1(s+1, p+1);
    }

// solution 2, recursive
// http://n00tc0d3r.blogspot.com/2013/05/regular-expression-matching.html?view=flipcard
    bool isMatch(const char *s, const char *p) {    
     if (!s) {
         return !p;
     }
     if (*p == '\0') {
         return *s == '\0';
     }
   
     // next char is not '*': do current char match?  
     if (*(p+1) == '\0' || *(p+1) != '*') {  
       if (*s == '\0') {
           return false;
       }
       return ((*p == '.' || *s == *p)  && isMatch(++s, ++p));  
   }  
   
   // next char is '*'  
   // current char match, zero or more repeats
   while (*s != '\0' && (*p == '.' || *s == *p)) {  
     if (isMatch(s, p+2)) {
         return true;
     }
     s++;  
   }  
   // zero  
   return isMatch(s, p+2);  
   } 
};
