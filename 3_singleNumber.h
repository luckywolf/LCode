/*
https://oj.leetcode.com/problems/single-number/

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
public:
// XOR
    int singleNumber_1(int A[], int n) {
        assert(n > 0);
        int res = A[0];
        for (int i = 1; i < n; ++i) {
            res ^= A[i];
        }
        return res;
    }
// if A[] is modifiable
    int singleNumber(int A[], int n) {
        assert(n > 0);
        for (int i = 1; i < n; ++i) {
            A[0] ^= A[i];
        }
        return A[0];
    }
};
