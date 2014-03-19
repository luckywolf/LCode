class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        bool setFirstRowZero = false;
        for (int i = 0 ; i < n; ++i) {
            if (matrix[0][i] == 0) {
                setFirstRowZero = true;
                break;
            }
        }
        bool setFirstColZero = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                setFirstColZero = true;
                break;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (setFirstRowZero) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (setFirstColZero) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
