class Solution {
public:
// Solution 1: recursive
    bool isValid(vector<int> &board, int row, int column) {
        for (int i = 0;  i < row; ++i) {
            if (column == board[i] || abs(row - i) == abs(column - board[i])) {
                return false;
            }
        }
        return true;
    }

    int totalNQueens(int n) {
        vector<int> board(n, -1);
        int res = 0;
        totalNQueensRe(n, 0, board, res);
        return res;
    }
    
    void totalNQueensRe(int n, int row, vector<int> &board, int &res) {
        if (n == row) {
            res++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col)) {
                board[row] = col;
                totalNQueensRe(n, row+1, board, res);
                board[row] = -1;
            }
        }
    }

// Solution 2, iterative
    int totalNQueens_2(int n) {
        vector<int> board(n, -1);
        int res = 0;
        int row = 0, col = 0;
        while (row < n) {
            while (col < n) {
                if (isValid(board, row, col)) {
                    board[row] = col;
                    col = 0;
                    break;
                } else {
                    col++;
                }
            }
            if (board[row] == -1) {
                if (row == 0) {
                    break;
                } else {
                    row--;
                    col = board[row]+1;
                    board[row] = -1;
                    continue;
                }
            }
            if (row == n-1) {
                res++;
                col = board[row]+1;
                board[row] = -1;
                continue;
            }
            row++;
        }
        return res;
    }
    
};
