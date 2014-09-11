/*
https://oj.leetcode.com/problems/pascals-triangle/

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
// first try, row and lastRow are actually not needed
    vector<vector<int> > generate_1(int numRows) {
        vector<vector<int>> res;
        vector<int> lastRow;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row;
            row.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                row.push_back(lastRow[j] + lastRow[j+1]);
            }
            if (i > 0) {
                row.push_back(1);
            }
            res.push_back(row);
            lastRow = row;
        }
        return res;
        
    }
// optimized
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i) {
            res[i].push_back(1);
            for (int j = 0; j < i - 1; j++) {
                res[i].push_back(res[i-1][j] + res[i-1][j+1]);
            }
            if (i > 0) {
                res[i].push_back(1);
            }
        }
        return res;
    }
};
