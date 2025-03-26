class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
    int res = INT_MAX, ops = 0;
    vector<int> v, dp(grid.size() * grid[0].size());
    for (auto &row : grid)
        v.insert(end(v), begin(row), end(row));
    sort(begin(v), end(v));
    for (int i = 0; i < v.size() - 1; ++i) {
        if ((v[i + 1] - v[i]) % x)
            return -1;
        dp[i + 1] = dp[i] + (i + 1) * (v[i + 1] - v[i]) / x;
    }
    for (int i = v.size() - 1; i > 0; --i) {
        ops += (v.size() - i) * (v[i] - v[i - 1]) / x;
        res = min(res, ops + dp[i - 1]);
    }
    return res == INT_MAX ? 0 : res;
}
};