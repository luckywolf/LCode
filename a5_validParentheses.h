/*
https://oj.leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    // optimzied concise code
    bool isValid_1(string s) {
        stack<char> par;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                par.push(s[i]);
            } else if (par.empty()) {
                return false;
            } else { // '}', ']' or ')'
                char top = par.top();
                if (s[i] == '}' && top == '{' ||
                    s[i] == ']' && top == '[' ||
                    s[i] == ')' && top == '('){
                        par.pop();
                } else {
                    return false;
                }
            }
        }
        return par.empty(); // possible bugs
    }
    
    // use switch clause
    bool isValid(string s) {
        stack<char> par;
        for (int i = 0; i < s.size(); ++i) {
            switch(s[i]) {
                case '(':
                case '[':
                case '{':
                    par.push(s[i]);
                    break;
                case ')':
                    if (par.empty() || par.top() != '(') {
                        return false;
                    }
                    par.pop();
                    break;
                case ']':
                    if (par.empty() || par.top() != '[') {
                        return false;
                    }
                    par.pop();
                    break;
                case '}':
                    if (par.empty() || par.top() != '{') {
                        return false;
                    }
                    par.pop();
                    break;
            }
        }
        return par.empty();
    }
};
