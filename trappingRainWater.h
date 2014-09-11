/*
https://oj.leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
*/
class Solution {
public:
    // first try, leftMax and rightMax doesn't include A[i] itself.
    int trap_1(int A[], int n) {
        int leftMax = 0;
        int leftBound[n];
        leftBound[0] = 0;
        for (int i = 1;  i < n; ++i) {
            leftMax = max(leftMax, A[i-1]);
            leftBound[i] = leftMax;
        }
        int res = 0;
        int rightMax = A[n-1];
        for (int i = n - 2; i > 0; --i) {
            rightMax = max(rightMax, A[i + 1]);
            int temp = min(rightMax, leftBound[i]) - A[i];
            res +=  temp > 0 ? temp: 0;
        }
        return res;
    }
    
    // Optimized,
    // lMax and rMax include A[i] itself, so we don't need to compare the result (temp) with 0
    int trap(int A[], int n) {
        int left[n];
//        int right[n];        
        
        int lMax = A[0];
        for (int i = 0; i < n; ++i) {
            lMax = max(lMax, A[i]);
            left[i] = lMax;
        }
        
        int rMax = A[n-1];
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            rMax = max(rMax, A[i]);
//            right[i] = rMax;
            res += min(left[i], rMax) - A[i];
        }
        return res;
    }
};
