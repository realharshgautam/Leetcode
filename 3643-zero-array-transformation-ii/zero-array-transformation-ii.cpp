class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
    int i = 0, j = 0;
    vector<int> line(nums.size() + 1);
    for (int cur = 0; i < nums.size(); cur += line[++i]) {
        for (; j < q.size() && cur < nums[i]; ++j)
            if (q[j][1] >= i) {
                if (q[j][0] <= i)
                    cur += q[j][2];
                else
                    line[q[j][0]] += q[j][2];
                line[q[j][1] + 1] -= q[j][2];                
            }
        if (cur < nums[i])
            break;
    }
    return i == nums.size() ? j : -1;
}
};