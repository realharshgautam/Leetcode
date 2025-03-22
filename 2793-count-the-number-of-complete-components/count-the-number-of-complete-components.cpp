class Solution {
public:
    void dfs(int i, vector<vector<int>> &al, unordered_set<int> &s) {
    if (s.insert(i).second)
        for (int j : al[i])
            dfs(j, al, s);
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> al(n);
    int res = 0;
    for (const auto &e : edges) {
        al[e[0]].push_back(e[1]);
        al[e[1]].push_back(e[0]);
    }
    unordered_set<int> ms;
    for (int i = 0; i < n; ++i) {
        if (ms.count(i) == 0) {
            unordered_set<int> s;
            dfs(i, al, s);
            res += all_of(begin(s), end(s), [&](int i){ return al[i].size() == s.size() - 1; });
            ms.insert(begin(s), end(s));
        }
    }
    return res;
}
};