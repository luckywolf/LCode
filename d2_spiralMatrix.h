/*
https://oj.leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
class Solution {
public:
// tail recursion
    vector<int> spiralOrder_1(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }        
        int m = matrix.size(), n = matrix[0].size();
        spiralOrderRe(matrix, m, n, 0, res);
        return res;
    }
    
    void spiralOrderRe(vector<vector<int>> &matrix, int m, int n,
                              int level, vector<int> &result) {
        if (m <= 0 || n <= 0) {
            return;
        }
        if (m == 1) {
            for (int i = 0; i < n; i++) {
                result.push_back(matrix[level][level+i]);
            }
            return;
        }
        if (n == 1) {
            for (int i = 0; i < m; i++) {
                result.push_back(matrix[level+i][level]);
            }
            return;
        }
        for (int i = 0; i < n - 1; ++i) {
            result.push_back(matrix[level][level+i]);
        }
        for (int i = 0; i < m - 1 ; ++i) {
            result.push_back(matrix[level+i][level+n-1]);
        }
        for (int i = 0; i < n - 1; ++i) {
            result.push_back(matrix[level+m-1][level+n-1-i]);
        }
        for (int i = 0; i < m - 1; ++i) {
            result.push_back(matrix[level+m-1-i][level]);
        }
        spiralOrderRe(matrix, m-2, n-2, level+1, result); 
    }
    
// iterative
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int beginX = 0, endX = matrix[0].size() - 1;
        int beginY = 0, endY = matrix.size() - 1;
        while (true) {
            for (int i = beginX; i <= endX; ++i) {
                res.push_back(matrix[beginY][i]);
            }
            if (++beginY > endY) {
                break;
            }
            for (int i = beginY; i <= endY; ++i) {
                res.push_back(matrix[i][endX]);
            }
            if (beginX > --endX) {
                break;
            }
            for (int i = endX; i >= beginX; --i) {
                res.push_back(matrix[endY][i]);
            }
            if (beginY > --endY) {
                break;
            }
            for (int i = endY; i >= beginY; --i) {
                res.push_back(matrix[i][beginX]);
            }
            if (++beginX > endX) {
                break;
            }
        }
        return res;
    }
};
