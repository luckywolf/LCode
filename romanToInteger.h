class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> symbol;
        symbol['I'] = 1;
        symbol['V'] = 5;
        symbol['X'] = 10;
        symbol['L'] = 50;
        symbol['C'] = 100;
        symbol['D'] = 500;
        symbol['M'] = 1000;
        int n = s.size();
        for (int i = 0; i < n-1; i++) {
            if (symbol[s[i]] < symbol[s[i+1]]) {
                res -= symbol[s[i]];
            } else {
                res += symbol[s[i]];
            }
        }
        res += symbol[s[n-1]];
        return res;
    }
};
