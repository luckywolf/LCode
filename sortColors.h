class Solution {
public:

    // first try
    // i: the first element after "0"s
    // j: the first element before "2"s
    // k: iterator
    void sortColors_1(int A[], int n) {
        int i = 0, j = n-1;
        while (i < n && A[i] == 0) {
            i++;
        }
        while (j >= 0 && A[j] == 2) {
            j--;
        }
        int k = i;
        while (k <= j) {
            if (A[k] == 0) {
                swap(A[k++], A[i++]); // since k >= i, so A[k] == 1 here;
            } else if (A[k] == 2) {
                swap(A[k], A[j--]);
            } else {
                k++;
            }
        }
    }
    
    // optimized
    // zero: the last element of "0"s
    // two: the first lement of "2"s
    // k: iterator
    void sortColors(int A[], int n) {
        int zero = -1, two =  n;
        int k = 0;
        while (k < two){
            if (A[k] == 0) {
                swap(A[++zero], A[k++]);
            } else if (A[k] == 1) {
                k++;
            } else {
                swap(A[--two], A[k]);
            }
        }
    }
};
