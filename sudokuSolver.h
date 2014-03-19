class Solution {
public:
   void solveSudoku(vector<vector<char> > &board) {
       solveSudokuRe(board);
    }

    bool solveSudokuRe(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 1; k <= 9; ++k) {
                        board[i][j] = k + '0';
                        if (isValid(board, i, j) && solveSudokuRe(board)) {
                            return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>> &board, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (i != col && board[row][i] == board[row][col] ||
                i != row && board[i][col] == board[row][col]) {
                return false;
            }
        }
        int boxI = row / 3 * 3, boxJ = col / 3 * 3;
        for (int i = boxI; i < boxI + 3; ++i) {
            for (int j = boxJ; j < boxJ + 3; ++j) {
                if (i != row && j != col && board[i][j] == board[row][col]) {
                    return false;
                }
            }
        }
        return true;
    }
};
