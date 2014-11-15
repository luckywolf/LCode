/*
https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/
/*
For case where AL == AM == AR, the minimum could be on AM¡¯s left or right side 
(eg, [1, 1, 1, 0, 1] or [1, 0, 1, 1, 1]). 
In this case, we could not discard either subarrays and therefore 
such worst case degenerates to the order of O(n).
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int left  = 0;
        int right = n - 1;
        // because there always exists a solution, "left < right" instead of "left <= right" is used
        // because there exist duplciated elements, num[left] >= num[right] is needed
        while (left < right && num[left] >= num[right]) {
            int mid = left + (right - left) / 2;
            if (num[mid] > num[right]) {
                left = mid + 1;
            } else if (num[mid] < num[left]) {
                right = mid;
            } else {
                ++left; // A[L] == A[M] == A[R]
            }
        }
        return num[left];
    }
};
