class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& n1, vector<vector<int>>& n2) {
    int i = 0, j = 0, sz1 = n1.size(), sz2 = n2.size();
    vector<vector<int>> res;
    while (i < sz1 || j < sz2) {
        int id = min(i < sz1 ? n1[i][0] : INT_MAX, j < sz2 ? n2[j][0] : INT_MAX);
        res.push_back({id, 0});
        if (i < sz1 && n1[i][0] == id)
            res.back()[1] += n1[i++][1];
        if (j < sz2 && n2[j][0] == id)
            res.back()[1] += n2[j++][1];
    }
    return res;
}
};