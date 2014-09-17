/*
https://oj.leetcode.com/problems/simplify-path/

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
class Solution {
public:
    // first try
    string simplifyPath_1(string path) {
        stack<string> stk;
        int n = path.size();
        if (path.empty() || path[0] != '/') {
            return NULL;
        }
        
        int i = 0;
        while (i < n) {
            while (path[i] == '/' && i < n) {
                i++;
            }
            if (i == n) {
                break;
            }
            int start = i;
            while (path[i] != '/' && i < n) {
                i++;
            }
            string element = path.substr(start, i - start);
            if (element == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (element != ".") {
                    stk.push(element);
            }
        }
        
        if (stk.empty()) {
            return "/";
        }
        string res;
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        return res;
    }
    
    // use more string API and not use stack
    string simplifyPath(string path) {
        if (path.empty() || path[0] != '/') {
            return NULL;
        }
        path = path + "/";
        string res;
        size_t i = path.find_first_of('/'), start = 0;
        while (i != string::npos) {
            string element = path.substr(start, i - start);
            if (element == "..") {
                if (!res.empty()) {
                    res.resize(res.find_last_of('/'));
                }
            } else if (!element.empty() && element != ".") {
                res += "/";
                res += element;
            }
            start = i + 1;
            i = path.find_first_of('/', start);
        }
        return res.empty() ? "/" : res;
    }
};
