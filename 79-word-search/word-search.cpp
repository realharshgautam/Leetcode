class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        function<bool(int, int, int)> backtrack = [&](int i, int j, int k) {
            if (k == word.length()) {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) {
                return false;
            }
            
            char temp = board[i][j];
            board[i][j] = '\0';
            
            if (backtrack(i + 1, j, k + 1) || backtrack(i - 1, j, k + 1) || 
                backtrack(i, j + 1, k + 1) || backtrack(i, j - 1, k + 1)) {
                return true;
            }
            
            board[i][j] = temp; 
            return false;
        };
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtrack(i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};