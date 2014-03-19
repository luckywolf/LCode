class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0]) {
                    if (existRe(board, i, j, visited, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
        
    bool existRe(vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited,
                 string word, int k) {
        if (k == word.size()) {
            return true;
        } 
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
            visited[i][j] || board[i][j] != word[k]) {
            return false;
        }
        visited[i][j] = true;
        if ( existRe(board, i-1, j, visited, word, k+1) || 
             existRe(board, i+1, j, visited, word, k+1) ||
             existRe(board, i, j-1, visited, word, k+1) ||
             existRe(board, i, j+1, visited, word, k+1)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }    
};
