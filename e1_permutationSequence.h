/*
https://oj.leetcode.com/problems/permutation-sequence/

The set [1,2,3,бн,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

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
