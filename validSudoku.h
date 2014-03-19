class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool used[9];
        for (int i = 0; i < 9; ++i) {
            memset(used, false, sizeof(used));
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (used[board[i][j] - '1']) {
                    return false;
                }
                used[board[i][j] - '1'] = true;
            }
        }
        
        for (int j = 0; j < 9; ++j) {
            memset(used, false, sizeof(used));
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (used[board[i][j] - '1']) {
                    return false;
                }
                used[board[i][j] - '1'] = true;
            }
        }
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                memset(used, false, sizeof(used));
                for (int iIdx = 0; iIdx < 3; iIdx++) {
                    for (int jIdx = 0; jIdx < 3; jIdx++) {
                         if (board[i+iIdx][j+jIdx] == '.') {
                             continue;
                         }
                         if (used[board[i+iIdx][j+jIdx] - '1']) {
                             return false;
                         }
                         used[board[i+iIdx][j+jIdx] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};
