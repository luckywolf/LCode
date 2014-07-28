class Solution {
public:
   // first try
    void merge_1(int A[], int m, int B[], int n) {
        for (int i = m+n-1, j = m-1, k = n-1; i >= 0; i--) {
            if (j < 0) {
                A[i] = B[k];
                k--;
            } else if (k < 0) {
                A[i] = A[j];
                j--;
            } else if (B[k] >= A[j]) {
                A[i] = B[k];
                k--;
            } else {
                A[i] = A[j];
                j--;
            }
        }
    }
    
    // optimized
    void merge(int A[], int m, int B[], int n) {
        int i = m+n-1, j = m-1, k = n-1;
        while (j >= 0 && k >= 0) {
            if (A[j] < B[k]) {
                A[i--] = B[k--];
            } else {
                A[i--] = A[j--];
            }
        }
        while (k >= 0) {
            A[i--] = B[k--];
        }
    }
    
        // second round
    void merge_3(int A[], int m, int B[], int n) {
        assert(m >= 0 && n >= 0);
        if (n == 0) {
            return;
        }
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
    
    // third round
    void merge(int A[], int m, int B[], int n) {
        assert(m >= 0 && n >= 0);
        if (n == 0) {
            return;
        }
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }
    }
};
