class Solution {
   public:
    bool safe(vector<string>& board, int row, int col) {
        int r = row, c = col;
    // Check lower left diagonal
        while (r >= 0 && c >= 0) {
            if (board[r--][c--] == 'Q') return false;
        }

        r = row;
        c = col;


        while (c >= 0) {
            if (board[r][c--] == 'Q') return false;
        }
        // Reset to the original position
        r = row;
        c = col;

        // Check lower left diagonal
        while (r < board.size() && c >= 0) {
            if (board[r++][c--] == 'Q') return false;
            
        }
        return true;
    }
    void func(int col, vector<vector<string>>& ans, vector<string>& board) {
        if (col == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < board.size(); row++) {
            if (safe(board, row, col)) {
                board[row][col] = 'Q';
                func(col + 1, ans, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        func(0, ans, board);
        return ans;
    }
};