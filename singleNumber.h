class Solution {
public:
// XOR
    int singleNumber_1(int A[], int n) {
        assert(n > 0);
        int res = A[0];
        for (int i = 1; i < n; ++i) {
            res ^= A[i];
        }
        return res;
    }
// if A[] is modifiable
    int singleNumber(int A[], int n) {
        assert(n > 0);
        for (int i = 1; i < n; ++i) {
            A[0] ^= A[i];
        }
        return A[0];
    }
};
