/*
https://oj.leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    /* solution: two pointers */
    int removeElement(int A[], int n, int elem) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[res++] = A[i];
            }
        }
        return res;
    }
};
