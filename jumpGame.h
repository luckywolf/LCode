/*
https://oj.leetcode.com/problems/jump-game/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
// greedy 
    bool canJump(int A[], int n) {
        if (n < 1) {
            return false;
        }
        int lastStepMax = A[0];
        int max = lastStepMax;
        for (int i = 0; i <= lastStepMax; i++) {
            if (max >= n-1) {
                return true;
            }
            if (i + A[i] > max) {
                max = i + A[i];
            }
            if (i == lastStepMax) {
                lastStepMax = max;
            }
        }
        return false;
    }
    
// optimized
    bool canJuam(int A[], int n) {
        int reach = 0;
        for (int i = 0; i <= reach && reach < n-1; i++) {
            reach = max(reach, i + A[i]);
        }
        return reach >= n-1;
    }
};
