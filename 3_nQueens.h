/*
https://oj.leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
public:
// Solution 1, recursive
    vector<vector<string> > solveNQueens_1(int n) {
        vector<vector<int>> queens;
        vector<int> solution(n, -1);
        solveNQueensRe(n, 0, solution, queens);
        // print results
        vector<vector<string>> res;
        for (int k = 0; k < queens.size(); k++) {
            vector<string> output;
            for (int i = 0; i < n; ++i) {
                string temp(n, '.');
                temp[queens[k][i]] = 'Q';
                output.push_back(temp);
            }
            res.push_back(output);
        }
        return res;
    }
    
    void solveNQueensRe(int n, int row, vector<int> &solution, vector<vector<int>> &queens) {
        if (row == n) {
            queens.push_back(solution);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, solution)) {
                solution[row] = col;
                solveNQueensRe(n, row+1, solution, queens);
                solution[row] = -1;
            }
        }
    }
    
    bool isValid(int row, int col, vector<int> &solution) {
        for (int i = 0; i < row; ++i) {
            if (solution[i] == col || abs(row - i)  == abs(col - solution[i])) {
                return false;
            } 
        }
        return true;
    }
    
// Solution 2, iterative
    vector<vector<string> > solveNQueens(int n) {
        vector<int> board(n, -1);
        vector<vector<int>> queens;
        int row = 0, col = 0;
        while (row < n) {
            while (col < n) {
                if (isValid(row, col, board)) {
                    board[row] = col;
                    col = 0; //we need to check from the next row, so set column to 0 here.
                    break;
                } else {
                    col++; // check next column
                }
            }
            if (board[row] == -1) { // we didn't find the Queen position in this row
                if (row == 0) { // if this is row 0, means we have finshed backtracking and all the solution have been found
                    break;
                } else {
                    row--; 
                    col = board[row]+1; // move last row's Queen to its next column
                    board[row] = -1; // clear last row's Queen and continue backtracking
                    continue;
                }
            }
            if (row == n-1) { // we have set the Queen in last row, means we have found a solution
                queens.push_back(board);
                //Cannot stop here, coz we need to find all the solutions. We need to clear the Queen  in this row, can continue backtracking from its next column. 
                col = board[row] + 1; // clear this column's Queen and backtacking from the next column
                board[row] = -1; 
                continue;
            }
            row++; //Check next row
        }
        
        // print results
        vector<vector<string>> res;
        for (int k = 0; k < queens.size(); k++) {
            vector<string> output;
            for (int i = 0; i < n; ++i) {
                string temp(n, '.');
                temp[queens[k][i]] = 'Q';
                output.push_back(temp);
            }
            res.push_back(output);
        }
        return res;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
};
