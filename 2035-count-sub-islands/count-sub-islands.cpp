class Solution {
public:
    int r, c;  // Number of rows and columns in the grid
    const int d[5] = {0, 1, 0, -1, 0};  // Directions array for traversing up, right, down, and left

    // Helper function to check if a cell (i, j) is outside the grid boundaries
    inline bool outside(int i, int j) {
        return i < 0 || i >= r || j < 0 || j >= c;
    }

    // Depth-First Search (DFS) to explore islands in grid2 and check if they are sub-islands of grid1
    bool dfs(int i, int j, int mark, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // If the current cell in grid1 is not land, return false (not a sub-island)
        if (grid1[i][j] != 1) return false;

        // Mark the current cell in grid2 as visited with a unique marker
        grid2[i][j] = mark;

        bool isSub = true;  // Assume the island is a sub-island until proven otherwise

        // Traverse in all four possible directions
        for (int a = 0; a < 4; a++) {
            int s = i + d[a], t = j + d[a + 1];  // Calculate the next cell coordinates

            // If the next cell is outside the grid or already visited, skip it
            if (outside(s, t) || grid2[s][t] != 1) continue;

            // If the next cell in grid1 is not land, mark the island as not a sub-island
            if (grid1[s][t] != 1) isSub = false;

            // Recursively continue DFS; if any part of the island is not a sub-island, mark it as false
            if (!dfs(s, t, mark, grid1, grid2)) 
                isSub = false;
        }

        return isSub;  // Return true if the whole island is a sub-island, otherwise false
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        r = grid1.size();  // Number of rows in the grid
        c = grid1[0].size();  // Number of columns in the grid
        int cnt = 0, mark = 2;  // Counter for sub-islands and marker for visited cells

        // Iterate over each cell in grid2
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // If a cell is part of an island (land) in grid2, start a DFS
                if (grid2[i][j] == 1) {
                    // If the DFS confirms it as a sub-island, increment the count
                    cnt += dfs(i, j, mark++, grid1, grid2);
                }
            }
        }

        return cnt;  // Return the total count of sub-islands
    }
};



auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();