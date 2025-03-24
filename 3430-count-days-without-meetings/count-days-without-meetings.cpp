class Solution {
public:
    int countDays(int days, vector<vector<int>>& meets) {
    int res = 0, cur = 1;
    sort(begin(meets), end(meets));
    for (const auto &m : meets) {
        res += max(0, m[0] - cur);
        cur = max(cur, m[1] + 1);
        if (cur > days)
            break;
    }
    return res + max(0, days - cur + 1);
}
};