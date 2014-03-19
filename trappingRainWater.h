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
