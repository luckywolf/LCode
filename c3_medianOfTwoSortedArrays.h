/*
https://oj.leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
class Solution {
public:
// O(m+n)
    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
        int total = m + n;
        int midOne = 0, midTwo = 0;
        int aj = 0, bj = 0;
        for (int i = 0, aj = 0, bj = 0; i <= total / 2; i++) {
            int a = (aj == m) ? INT_MAX : A[aj];
            int b = (bj == n) ? INT_MAX : B[bj];
            midOne = midTwo;
            midTwo = min(a, b);
            if (a < b) {
                aj++;
            } else {
                bj++;
            }
        }
        if (total & 0x1) {
            return midTwo;
        } else {
            return (midOne + midTwo) / 2.0;
        }
    }
// O(lg(m+n))
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total  = m + n;
        if (total & 0x1) {
            return findKthSmallestElement(A, m, B, n, total/2 + 1);
        } else {
            return (findKthSmallestElement(A, m, B, n, total / 2) +
                   findKthSmallestElement(A, m, B, n, total / 2 + 1)) / 2.0;
        }
    }
    
    int findKthSmallestElement(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findKthSmallestElement(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k-1];
        }
        int i = min(k/2, m); // how to choose i
        int j = k - 1 - i;
        int Ai_1 = (i- 1 < 0) ? INT_MIN : A[i-1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj_1 = (j - 1 < 0) ? INT_MIN : B[j-1];
        int Bj = (j == n) ? INT_MAX : B[j];
        if (Ai_1 <= Bj && Bj <= Ai) { // no assumption that duplicated elements cannot exist
            return B[j];
        } else if (Bj_1 <= Ai && Ai <= Bj) {
            return A[i];
        } else if (Ai <= Bj) {
            return findKthSmallestElement(A+i+1, m-i-1, B, j, k-i-1);
        } else {
            return findKthSmallestElement(A, i, B+j+1, n-j-1, k-j-1);
        }
    }
};
