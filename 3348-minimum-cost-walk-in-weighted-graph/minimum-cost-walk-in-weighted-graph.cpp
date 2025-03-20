class Solution {
public:
   vector<int> ds, cost;
int find(int i) {
    return ds[i] < 0 ? i : ds[i] = find(ds[i]);
}
vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    ds = cost = vector<int>(n, -1);
    for (auto &e : edges) {
        int p1 = find(e[0]), p2 = find(e[1]);
        if (p1 != p2) {
            cost[p1] &= cost[p2];
            ds[p2] = p1;
        }
        cost[p1] &= e[2];
    }
    vector<int> res;
    for (auto q : query) {
        if (q[0] == q[1])
            res.push_back(0);
        else if (int p1 = find(q[0]), p2 = find(q[1]); p1 != p2)
            res.push_back(-1);
        else
            res.push_back(cost[p1]);
    }
    return res;
}
};