/*
https://oj.leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
class Solution {
public:
// assumption: if there doesn't exist such a path, return -1
    int jump(int A[], int n) {
        assert(n >= 0);
        int lastStepReach = 0, reach = 0;
        int steps  = 0;
        for (int i = 0; i <= min(reach, n-1) ; i++){
            if (i > lastStepReach) {
                steps++;
                lastStepReach = reach;
            }
            reach = max(reach, i + A[i]);
        }
        if (reach >= n - 1) {
            return steps;
        } else {
            return -1;
        }
    }
};
