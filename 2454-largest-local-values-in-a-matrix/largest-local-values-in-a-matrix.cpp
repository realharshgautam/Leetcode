#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize ("-ffloat-store")

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));

        for(int i = 1; i < n - 1; ++i) {
            for(int j = 1; j < n - 1; ++j) {
                int temp = 0;

                for(int k = i - 1; k <= i + 1; ++k) {
                    for(int l = j - 1; l <= j + 1; ++l) {
                        temp = max(temp, grid[k][l]);
                    }
                }

                res[i - 1][j - 1] = temp;
            }
        }

        return res;
    }
};