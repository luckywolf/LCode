class Solution {
public:
// first try, O(k) space
    vector<int> getRow_1(int rowIndex) {
        vector<int> res;
        vector<int> lastRow;
        for (int i = 0; i <= rowIndex; ++i) {
            res.clear();
            res.push_back(1);
            for (int j = 0; j < i - 1; j++) {
                res.push_back(lastRow[j] + lastRow[j+1]);
            }
            if (i > 0) {
                res.push_back(1);
            }
            lastRow = res;
        }
        return res;
    }
// optimized, lastRow is not needed, O(1) space
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i-1; j > 0; j--) {
                res[j] = res[j-1] + res[j];
            }
        }
        return res;
    }
    
};
