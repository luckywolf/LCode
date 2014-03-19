class Solution {
public:
// solution 1, O(n)
    int maxSubArray(int A[], int n) {
        int res = A[0], sum = A[0];
        for (int i = 1; i < n; ++i) {
            /*
            if (sum <= 0) {
                 sum = 0;
             }
             sum += A[i];
            <==>
            sum = max (A[i], sum + A[i]);
            */
            sum = max (A[i], sum + A[i]);
            res = max(res, sum);
        }
        return res;
    }
// solution 2, divide and conquer, O(nlgn)
    int maxSubArray_2(int A[], int n) {
        return maxSubArrayRe(A, 0, n-1);
    }
    
    int maxSubArrayRe(int A[], int start, int end) {
        if (start > end) {
            return INT_MIN;
        }
        int mid = start + (end - start) / 2;
        int lmax = maxSubArrayRe(A, start, mid-1);
        int rmax = maxSubArrayRe(A, mid+1, end);
        int mmax = A[mid];
        int sum = mmax;
        for (int i =  mid-1; i >= start; --i) {
            sum += A[i];
            if (sum > mmax) {
                mmax = sum;
            }
        }
        sum = mmax;
        for (int i = mid+1; i <= end; ++i) {
            sum += A[i];
            if (sum > mmax) {
                mmax = sum;
            }
        }
        return max(mmax, max(lmax, rmax));
    }
    
};
