#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<uint8_t> col1(m, 0);
        int sum = 0;
        for (auto& row : grid) {
            int x = 0;
            bool one = 0;
            for (int i = 0; i < m; i++) {
                one = (row[0] == 0) ^ (row[i] == 1);
                x = (x << 1) + one;
                col1[i] += one;
            }
            sum += x;
        }
        for (int i = 0; i < m; i++) {
            if (col1[i] <= n / 2) 
                sum += (1 << (m - 1 - i)) * (n - 2 * col1[i]);
        }
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();