class Solution {
public:
// DP: let F(i, j) denote the number of ways for S[0]…S[i] contain T[0]..T[j], 
// Then F(m-1, n-1) is our answer and we have
// if(S[i] != T[j])  F(i, j) = F(i-1, j);
// if(S[i] == T[j]) F(i, j) = F(i-1, j-1) + F(i-1, j);
    int numDistinct(string S, string T) {
        int m = S.size(), n = T.size();
        int matches[m][n];
        matches[0][0] = (S[0] == T[0]); 
        for (int i = 1; i < m; ++i) {
            matches[i][0] = matches[i-1][0] + (S[i] == T[0]); 
        }
        for (int j = 1; j < n; ++j) {
            matches[0][j] = 0;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matches[i][j] = matches[i-1][j] + (S[i] == T[j]) * matches[i-1][j-1];
            }
        }
        return matches[m-1][n-1];
    }
// Natual recursive, just for fun, TLE
/* 每次递归调用f(S, T)使用如下方法处理（假设S长度为n，T长度为m）：
    找出T[0]在S中的第一个位置i，则f(S, T) = f(S[i+1:n], T[1:m])
    则复杂度为f(n) = n*f(n-1) = n*(n-1)*f(n-2) = ... = n!
    Large Judge时容易TLE
*/
    int numDistinct_2(string S, string T) {
        int m = S.size(), n = T.size();
        if( n == 0){
            return 1;
        } else if(m == 0){
            return 0;
        } else{
            int res = 0;
            for(int i = 0; i < m; ++i){
                if(S[i] == T[0]){
                    res += numDistinct(S.substr(i+1, m-1), T.substr(1, n-1));
                }
            }
            return res;
        }
    }
    
};
