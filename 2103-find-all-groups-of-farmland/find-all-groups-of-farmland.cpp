class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size();
        int cols = land[0].size();
        unordered_set<string> visited;
        vector<vector<int>> result;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (land[i][j] == 1 && visited.find(to_string(i) + "," + to_string(j)) == visited.end()) {
                    vector<int> bounds = dfs(land, visited, i, j);
                    result.push_back(bounds);
                }
            }
        }

        return result;
    }

    vector<int> dfs(vector<vector<int>>& land, unordered_set<string>& visited, int x, int y) {
        stack<pair<int, int>> stack;
        stack.push({x, y});
        visited.insert(to_string(x) + "," + to_string(y));

        int minRow = x, minCol = y;
        int maxRow = x, maxCol = y;

        while (!stack.empty()) {
            auto current = stack.top();
            stack.pop();
            int curX = current.first, curY = current.second;

            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto& dir : directions) {
                int nx = curX + dir.first;
                int ny = curY + dir.second;

                if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size() &&
                    land[nx][ny] == 1 && visited.find(to_string(nx) + "," + to_string(ny)) == visited.end()) {
                    visited.insert(to_string(nx) + "," + to_string(ny));
                    stack.push({nx, ny});
                    minRow = min(minRow, nx);
                    minCol = min(minCol, ny);
                    maxRow = max(maxRow, nx);
                    maxCol = max(maxCol, ny);
                }
            }
        }

        return {minRow, minCol, maxRow, maxCol};
    }
};
