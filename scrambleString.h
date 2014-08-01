class Solution {
public:
// Recursion + pruning
    bool isScramble_1(string s1, string s2) {
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
    
// DP, O(n^3), may not be faster than above solution
    /*
    维护一个三维的数组：res[ len ][ start_s1 ][ start_s2 ]表示长度为len的，s1从start_s1开始，s2从start_s2开始是否能scramble。
    然后递归方程为：
    res[len][start_s1][start_s2] = （res[m][start_s1][start_s2] && res[len - m][start_s1 + m][start_s2 + m]）
                                     ||（res[m][start_s1][start_s2 + len - m] && res[len-m][start_s1 + m][start_s2]）。
    其中m是1到len-1的一个数。
    base case 是：如果len等于1的话， res[len][start_s1][start_s2] = (s1[start_s1] == s2[start_s2]);
    */
    bool isScramble(string s1, string s2) {  
        if(s1.size() != s2.size()) return false;  
        if(s1.size() == 0) return true;  
        if(s1 == s2) return true;  
        int n = s1.size();  
        bool *** res = new bool **[n+1];  
        for(int i = 1; i<= n; ++i){  
            res[i] = new bool*[n];  
            int len = i;  
            int start_s1 = 0;  
            int start_s2 = 0;  
            for(int j = 0; j <= n-len; ++j){//对s1的下标进行循环  
                start_s1 = j;  
                res[len][start_s1] = new bool[n];  
                for(int k = 0; k<= n-len; ++k){//对s2的下标进行循环  
                    start_s2 = k;  
                    res[len][start_s1][start_s2] = false;  
                    if(len == 1){  
                        res[len][start_s1][start_s2] = s1[start_s1] == s2[start_s2];  
                    }  
                    for(int m = 1; m < len; ++m){//判断子序列  
                        if(res[m][start_s1][start_s2] && res[len - m][start_s1 + m][start_s2 + m]){  
                            res[len][start_s1][start_s2] = true;  
                            break;  
                        }  
                        if(res[m][start_s1][start_s2 + len - m] &&  
                        res[len-m][start_s1 + m][start_s2]){  
                            res[len][start_s1][start_s2] = true;  
                            break;  
                        }  
                    }  
                }  
            }  
        }  
        return res[n][0][0];  
    }  
};
