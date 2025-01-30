class Solution {
public:
    bool possible(int n, vector<int> nums, int day, int k, int m) {
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= day)
                cnt++;
            else {
                noOfB += cnt / k;
                cnt = 0;
            }
        }
        noOfB += cnt / k;
        return noOfB >= m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        long long val = k * 1ll * m * 1ll;
        int n =nums.size();
        if (n < val)
            return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; ++i) {
            maxi = max(nums[i], maxi);
            mini = min(nums[i], mini);
        }
        int left = mini, right = maxi;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(n, nums, mid, k, m)) {
                right = mid - 1;
            } else
                left = mid + 1;
        }
        return left;
    }
};