class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int temp;
        for (int i = 0; i < n / 2; ++i) { // levels
            for (int j = i; j < n-1-i; ++j) { // each row/column
                temp = matrix[i][j]; //move up to temp
                matrix[i][j] = matrix[n-1-j][i]; // move left to up
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]; // move bottom to left
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]; // move right to bottom
                matrix[j][n-1-i] = temp; // move temp(up) to right
            }
        }
    }
};
