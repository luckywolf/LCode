/*
https://oj.leetcode.com/problems/spiral-matrix-ii/

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        int beginX = 0, endX = n-1;
        int beginY = 0, endY = n-1;
        int num = 1;
        while (true) {
            for (int i = beginX; i <= endX; ++i, ++num) {
                res[beginY][i] = num;
            }
            if (++beginY > endY) {
                break;
            }
            for (int i = beginY; i <= endY; ++i, ++num) {
                res[i][endX] = num;
            }
            if (beginX > --endX) {
                break;
            }
            for (int i = endX; i >= beginX; --i, ++num) {
                res[endY][i] = num;
            }
            if (beginY > --endY) {
                break;
            }
            for (int i = endY; i >= beginY; --i, ++num) {
                res[i][beginX] = num;
            }
            if (++beginX > endX) {
                break;
            }
        }
        return res;
    }
};
