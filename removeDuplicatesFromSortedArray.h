class Solution {
public:
   /* two pointers */
    int removeDuplicates(int A[], int n) {
        int length = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || A[i] != A[i-1]) {
                A[length++] = A[i]; 
            }
        }
        return length;
    }
};
