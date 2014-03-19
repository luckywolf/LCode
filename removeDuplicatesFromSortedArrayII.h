class Solution {
public:
    // solution 1: use a counter
    int removeDuplicates_1(int A[], int n) {
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
    
    // solution 2: use two comparisons
    int removeDuplicates(int A[], int n) {
        if (n < 3) {
            return n;
        }
        int length = 2;
        for (int i = 2; i < n; ++i){
            // pay attention to the condition, use length-1 and length-2, not i-1, not i-2
            if (A[i] != A[length-1] || A[i] != A[length-2]) { 
                A[length++] = A[i];
            }
        }
        return length;
    }
};
