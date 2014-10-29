/*
https://oj.leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements 
from B. The number of elements initialized in A and B are m and n respectively.
*/
class Solution {
public:
   // first try
    void merge_1(int A[], int m, int B[], int n) {
        for (int i = m+n-1, j = m-1, k = n-1; i >= 0; i--) {
            if (j < 0) {
                A[i] = B[k];
                k--;
            } else if (k < 0) {
                A[i] = A[j];
                j--;
            } else if (B[k] >= A[j]) {
                A[i] = B[k];
                k--;
            } else {
                A[i] = A[j];
                j--;
            }
        }
    }
    
    // optimized
    void merge_2(int A[], int m, int B[], int n) {
        int i = m+n-1, j = m-1, k = n-1;
        while (j >= 0 && k >= 0) {
            if (A[j] < B[k]) {
                A[i--] = B[k--];
            } else {
                A[i--] = A[j--];
            }
        }
        while (k >= 0) {
            A[i--] = B[k--];
        }
    }
    
   // even more optimized
    void merge_3(int A[], int m, int B[], int n) {
        assert(m >= 0 && n >= 0);
        int k = m+n-1, i = m-1, j = n-1;
        while (j >= 0) { // if B does not run out
            if (i >=0 && A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
    }
};
