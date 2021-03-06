/*
https://oj.leetcode.com/problems/first-missing-positive/

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space
*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; ++i) {
            if (A[i] <= 0 || A[i] > n) {
                continue;
            }
            while (A[i] - 1 != i && A[i] > 0 && A[i] <= n && A[i] != A[A[i]-1]) {
                swap(A[i], A[A[i]-1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (A[i] - 1 != i) {
                return i + 1;
            }
        }
        return n + 1; 
    }
};
