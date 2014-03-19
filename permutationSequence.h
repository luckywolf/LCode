class Solution {
public:
    string getPermutation(int n, int k) {
        string num;
        string res;
        int factorial = 1;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
            num.push_back('0' + i);
        }
        // change K from (1,n) to (0, n-1) to accord to index 
        k--;
        for (int i = n; i > 0; i--) {
            factorial /= i;
            int index = k / factorial;
            k %= factorial;
            res.push_back(num[index]);
            num.erase(num.begin()+index);
        }
        return res;
    }
};
