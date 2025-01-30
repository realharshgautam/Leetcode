class Solution {
private:
    bool canWePlace(vector<int> &nums, int dist, int minCnt) {
        int cnt = 1, last = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - last >= dist) {
                cnt++;
                last = nums[i];
            }
            if (cnt >= minCnt) return true;
        }
        return false;
    }

   public:
    int maxDistance(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1, high = nums[n - 1] - nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canWePlace(nums, mid, k) == true) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return high;
    }
};