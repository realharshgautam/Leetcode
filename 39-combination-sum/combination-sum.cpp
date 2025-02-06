class Solution {
   private:
    void func(vector<int>& nums, int n, int sum, vector<int>& list,
              vector<vector<int>>& ans) {
        if (sum == 0) {
            ans.push_back(list);
            return;
        }
        if (sum < 0) return;
        if (n < 0) return;

        func(nums, n - 1, sum, list, ans);

        list.push_back(nums[n]);
        func(nums, n, sum - nums[n], list, ans);
        list.pop_back();
    }

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        int n = candidates.size() - 1;
        func(candidates, n, target, list, ans);

        return ans;
    }
};