class Solution {
public:
// O(lg(mn)) = O(lgm + lgn)
    bool searchMatrix_1(vector<vector<int> > &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start  = 0, end = m*n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int row = mid / n, col = mid % n;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                end = mid - 1;
            } else {
                start = start + 1;
            }
        }
        return false;
    }
// O(lgm + lgn)
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                end = mid -1;
            } else {
                start = mid + 1;
            }
        }
        if (end < 0) {
            return false;
        }
        int row = end;
        start = 0; 
        end = n - 1;
        while (start <= end) {
            int mid = (start + end)  / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};
