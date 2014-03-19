class Solution {
public:
    // first try
    string countAndSay_1(int n) {
        string res = "1";
        if (n == 1) {
            return res;
        }
        for (int i = 1; i < n; ++i) {
            stringstream temp;
            int counter = 1;
            for (int j = 1; j < res.size(); j++) {
                if (res[j] == res[j-1]) {
                    counter++;
                } else {
                    temp << counter << res[j-1];
                    counter = 1;
                }
            }
            temp << counter << res[res.size()-1];
            temp >> res;
        }
        return res;
    }
    
    // optimized
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i) {
            stringstream temp;
            int j = 0;
            int m = res.size();
            while (j < m) {
                int k = j+1;
                while (k < m && res[k] == res[j]) {
                    k++;
                }
                temp << (k - j) << res[j];
                j = k;
            }
            temp >> res;
        }
        return res;
    }
};
