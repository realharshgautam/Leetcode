class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
    }
};