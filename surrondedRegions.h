class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                    bfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                 board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
            }
        }
    }
    
    // dfs cannot pass because of too many levels recursive calls.
    void dfs(vector<vector<char>> &board, int row, int col) {
        int m = board.size(), n = board[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }
        if (board[row][col] != 'O') {
            return;
        }
        board[row][col] = 'V';
        dfs(board, row-1, col);
        dfs(board, row+1, col);
        dfs(board, row, col-1);
        dfs(board, row, col+1);
    }
    
    void bfs(vector<vector<char>> &board, int row, int col) {
        if (board[row][col] != 'O') {
            return;
        }
        int m = board.size(), n = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= m || j < 0 || j >= n) {
                continue;
            }
            if (board[i][j] != 'O') {
                continue;
            }
            board[i][j] = 'V';
            q.push(make_pair(i-1, j));
            q.push(make_pair(i+1, j));
            q.push(make_pair(i, j-1));
            q.push(make_pair(i, j+1));
        }
    }
};
