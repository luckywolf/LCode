class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int lower =  -1;
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                lower = mid;
            }
            if (A[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        if (lower == -1) {
            return res;
        } else {
            res[0] = lower;
        }
        int upper = lower;
        start = 0, end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                upper = mid;
            }
            if (A[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        res[1] = upper;
        return res;
    }
};
