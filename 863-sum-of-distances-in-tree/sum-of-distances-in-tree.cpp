class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> res;

    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                res[child] = res[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.clear();
        count = vector<int>(n, 1);
        res = vector<int>(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);
        dfs2(0, -1);

        return res;
    }
};