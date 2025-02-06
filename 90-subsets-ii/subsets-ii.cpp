class Solution {
   private:
    void func(int ind, vector<int>& arr, vector<int>& nums,
              vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[ind]);
        func(ind + 1, arr, nums, ans);
        arr.pop_back();

        for (int i = ind + 1; i < nums.size(); i++) {
            if (nums[i] != nums[ind]) {
                func(i, arr, nums, ans);
                return;
            }
        }
        func(nums.size(), arr, nums, ans);
    }

   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        func(0, arr, nums, ans);
        return ans;
    }
};