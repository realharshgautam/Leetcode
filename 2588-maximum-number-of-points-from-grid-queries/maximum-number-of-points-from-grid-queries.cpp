class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rows = grid.size(), cols = grid[0].size();
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.emplace_back(queries[i], i);
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> result(queries.size(), 0);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        minHeap.emplace(grid[0][0], make_pair(0, 0));
        visited[0][0] = true;
        int points = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& [queryVal, queryIdx] : sortedQueries) {
            while (!minHeap.empty() && minHeap.top().first < queryVal) {
                auto [val, pos] = minHeap.top();
                minHeap.pop();
                int row = pos.first, col = pos.second;
                points++;

                for (auto& [dr, dc] : directions) {
                    int nr = row + dr, nc = col + dc;
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                        minHeap.emplace(grid[nr][nc], make_pair(nr, nc));
                        visited[nr][nc] = true;
                    }
                }
            }
            result[queryIdx] = points;
        }

        return result;
    }
};