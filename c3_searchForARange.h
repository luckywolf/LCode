/*
https://oj.leetcode.com/problems/search-for-a-range/

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int lower =  -1;
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                lower = mid;
            }
            if (A[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (lower == -1) {
            return res;
        } else {
            res[0] = lower;
        }
        int upper = lower;
        start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                upper = mid;
            }
            if (A[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        res[1] = upper;
        return res;
    }
};
