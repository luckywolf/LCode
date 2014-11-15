/*
https://oj.leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
// solution 1: tail recursion
    int search_1(int A[], int n, int target) {
        if (n <= 0) {
            return -1;
        } else {
            return searchRe(A, 0, n-1, target);
        }
    }
        
    int searchRe(int A[], int start, int end, int target) {    
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] >= A[start]) { // lower half is sorted
            if (A[start] <= target && target < A[mid]) {
                return searchRe(A, start, mid - 1, target);
            } else {
                return searchRe(A, mid + 1, end, target);
            }
        } else { // upper half is sorted
            if (A[mid] < target && target <= A[end]) {
                return searchRe(A, mid + 1, end, target);
            } else {
                return searchRe(A, start, mid - 1, target);
            }
        }
    }
// soluiton 2, optimized
    int search(int A[], int n, int target) {
        int start = 0, end  = n-1;
        while (start <= end) { // Because it may not find the target, <= instead of < is used.
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[start] <= A[mid]) { // lower half is sorted
                if (A[start] <= target && target < A[mid]) {
                    end = mid -1;
                } else {
                    start = mid + 1;
                }
            } else { // upper half it sorted
                if (A[mid] < target && target <= A[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
