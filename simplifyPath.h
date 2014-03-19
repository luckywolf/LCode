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
