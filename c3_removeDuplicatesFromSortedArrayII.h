/*
https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
class Solution {
public:
    // solution 2: use two comparisons
    int removeDuplicates_1(int A[], int n) {
        int length = 0;
        for (int i = 0; i < n; ++i){
            // pay attention to the condition, use length-1 and length-2, not i-1, not i-2
            if (i < 2 || A[i] != A[length-1] || A[i] != A[length-2]) { 
                A[length++] = A[i];
            }
        }
        return length;
    }
    // solution 2: use a counter
    int removeDuplicates_2(int A[], int n) {
        int length  = 0, duplicated = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || A[i] != A[i-1]) {
                A[length++] = A[i];
                duplicated = 0;
            } else if (duplicated == 0) {
                A[length++] = A[i];
                duplicated++;
            }
        }
        return length;
    }
};
