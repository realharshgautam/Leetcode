class Solution {
   public:
    int countSplits(vector<int> &nums, int maxSum) {
        int sum = 0;
        int splits = 1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            } else {
                splits++;
                sum = nums[i];
            }
        }
            return splits;
    }
    int splitArray(vector<int> &nums, int m) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while (low <= high) {
            int mid = (low + high) / 2;
            int splits = countSplits(nums, mid);
            if (splits > m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
            return low;
    }
};