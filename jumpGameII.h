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
