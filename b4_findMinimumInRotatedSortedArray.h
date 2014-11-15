/*
https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
You may assume no duplicate exists in the array.
*/

/*
There are two cases for two elements:

A = [1,2]
B = [2,1]
For A, 1 < 2 => AM < AR, and therefore it will set R = M => R = 0.

For B, 2 > 1 => AM > AR, and therefore it will set L = M + 1 => L = 1.

Therefore, it is clear that when L == R, we have found the minimum element.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int n = num.size();
        int left = 0, right = n - 1;
        // because there always exists a solution, "left < right" instead of "left <= right" is used
        // because there are not duplciated elements, num[left] >= num[right] is not needed
        while (left < right && num[left] > num[right]) { 
            int mid = left + (right - left) / 2;
            if (num[mid] > num[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return num[left];
    }
};
