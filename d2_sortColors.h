/*
https://oj.leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
class Solution {
public:

    // first try
    // i: the first element after "0"s
    // j: the first element before "2"s
    // k: iterator
    void sortColors_1(int A[], int n) {
        int i = 0, j = n-1;
        while (i < n && A[i] == 0) {
            i++;
        }
        while (j >= 0 && A[j] == 2) {
            j--;
        }
        int k = i;
        while (k <= j) {
            if (A[k] == 0) {
                swap(A[k++], A[i++]); // since k >= i, so A[k] == 1 here;
            } else if (A[k] == 2) {
                swap(A[k], A[j--]);
            } else {
                k++;
            }
        }
    }
    
    // optimized
    // zero: the last element of "0"s
    // two: the first lement of "2"s
    // k: iterator
    void sortColors(int A[], int n) {
        int zero = -1, two =  n;
        int k = 0;
        while (k < two){
            if (A[k] == 0) {
                swap(A[++zero], A[k++]);
            } else if (A[k] == 1) {
                k++;
            } else {
                swap(A[--two], A[k]);
            }
        }
    }
};
