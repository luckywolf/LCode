class Solution {
public:
// Recursion + pruning
    bool isScramble(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m != n) {
            return false;
        }
        vector<int> count(26, 0); // assumption: only lower case letters
        for (int i = 0; i < m; ++i) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
            
        }
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) {
                return false;
            }
        }
        if (m == 1) {
            return true;
        }
        for (int len = 1; len < m; ++len) {
            bool res = isScramble(s1.substr(0, len), s2.substr(0, len)) &&
                       isScramble(s1.substr(len, m - len), s2.substr(len, m - len));
            res |= isScramble(s1.substr(0, len), s2.substr(m - len, len)) &&
                   isScramble(s1.substr(len, m - len), s2.substr(0, m - len));
            if (res) {
                return true;
            }
        }
        return false;
    }
};
