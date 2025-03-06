class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& Intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        int n = Intervals.size();
        while (i < n && Intervals[i][1] < newInterval[0]) {
            res.push_back(Intervals[i]);
            i++;
        }
        while (i < n && Intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], Intervals[i][0]);
            newInterval[1] = max(newInterval[1], Intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while (i < n) {
            res.push_back(Intervals[i]);
            i++;
        }
        return res;
    }
};