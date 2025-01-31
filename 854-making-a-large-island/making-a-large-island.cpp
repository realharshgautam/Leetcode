class Solution {
    int d[5] = {1, 0, -1, 0, 1}; // Direction vectors
    int n;

    // Depth-First Search to mark island and calculate its size
    int dfs(int row, int col, int id, vector<vector<int>>& grid) {
        grid[row][col] = id; // Mark cell with island ID
        int cnt = 1;         // Initialize size of the island

        for (int i = 0; i < 4; i++) { // Explore all 4 directions
            int nr = row + d[i];
            int nc = col + d[i + 1];

            if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1)
                cnt += dfs(nr, nc, id, grid);
        }

        return cnt; // Return the total size of the island
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> key; // Store sizes of all islands
        int id = 2;      // Island IDs start from 2

        // Identify all islands and calculate their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    key.push_back(dfs(i, j, id++, grid));
            }
        }

        if (key.empty())
            return 1; // Grid contains no land

        int ans = 1;

        // Check all water cells and calculate potential island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int cnt = 1;

                    // Add sizes of neighboring islands
                    for (int k = 0; k < 4; k++) {
                        int nr = i + d[k];
                        int nc = j + d[k + 1];

                        if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                            grid[nr][nc] != 0 && key[grid[nr][nc] - 2] > 0)
                            cnt += key[grid[nr][nc] - 2],
                                key[grid[nr][nc] - 2] *=
                                -1; // Mark island as visited
                    }

                    // Reset the sizes of marked islands
                    for (int k = 0; k < 4; k++) {
                        int nr = i + d[k];
                        int nc = j + d[k + 1];

                        if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                            grid[nr][nc] != 0 && key[grid[nr][nc] - 2] < 0)
                            key[grid[nr][nc] - 2] *= -1; // Unmark island
                    }

                    ans = max(ans,
                              cnt); // Update the largest possible island size
                }
            }
        }

        return ans == 1 ? n * n : ans; // Return result
    }
};