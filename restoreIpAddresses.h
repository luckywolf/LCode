class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        restoreIpAddressesRe(s, 0, 0, ip, res);
        return res;
    }

// first try    
    void restoreIpAddressesRe_1(string &s, int start, int deep, string &ip,
                              vector<string> &result) {
        if (deep == 4 && start == s.size()) {
            ip.pop_back();
            result.push_back(ip);
            return;
        }
        if (deep == 4 || start == s.size()) {
            return;
        }
        for (int i = 0;  i < 3; ++i) {
            if (start+i < s.size()) {
                string temp = s.substr(start, i+1);
                int digits = atoi(temp.c_str());
                if (i == 0 || i == 1 && digits >= 10 ||
                    i == 2 && digits >=100 & digits <= 255) {
                    int size = ip.size();
                    ip.append(temp);
                    ip.push_back('.');
                    restoreIpAddressesRe_1(s, start+i+1, deep+1, ip, result);
                    ip.resize(size);
                }
            }
        }
    }
// optimized
    void restoreIpAddressesRe(string &s, int start, int deep, string &ip,
                              vector<string> &result) {
        if (deep == 4 && start == s.size()) {
            result.push_back(ip);
            return;
        }
        if (deep == 4 || start == s.size()) {
            return;
        }
        int num = 0, origSize = ip.size();
        if (origSize != 0) {
            ip.push_back('.');
        }
        for (int i = start; i < s.size(); ++i) {
            num = num * 10 + s[i] - '0';
            if (num > 255) {
                break;
            }
            ip.push_back(s[i]);
            restoreIpAddressesRe(s, i+1, deep+1, ip, result);
            if (num == 0) {
                break;
            }
        }
        ip.resize(origSize);
    }
    
};
