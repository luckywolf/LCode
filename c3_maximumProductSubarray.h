/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

e.g [-3, 4, -2] => 24
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
        // max and min product ending at element i
        vector<int> maxDp(n), minDp(n);
        maxDp[0] = minDp[0] = A[0];
        int res = maxDp[0];
        for (int i = 1; i < n; ++i) {
            maxDp[i] = max(A[i] * minDp[i-1], max(A[i], A[i] * maxDp[i-1]));
            minDp[i] = min(A[i] * maxDp[i-1], min(A[i], A[i] * minDp[i-1]));
            if (maxDp[i] > res) {
                res = maxDp[i];
            }
        }
        return res;
    }
};