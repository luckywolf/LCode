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
