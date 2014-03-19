class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int start  = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end + 1;
        // or return start;
    }
};
