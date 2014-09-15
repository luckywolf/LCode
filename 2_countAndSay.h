/*
https://oj.leetcode.com/problems/count-and-say/

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
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
