class Solution {
   private:
    bool func(vector<vector<char> >& v, int i, int j, string& s, int k) {
        if (k == s.length()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() ||
            s[k] != v[i][j]) {
            return false;
        }
        bool ans = false;
        char x = v[i][j];
        v[i][j] = ' ';
        ans |= func(v, i + 1, j, s, k + 1);
        ans |= func(v, i - 1, j, s, k + 1);
        ans |= func(v, i, j + 1, s, k + 1);
        ans |= func(v, i, j - 1, s, k + 1);
        v[i][j] = x;
        return ans;
    }

   public:
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (func(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};