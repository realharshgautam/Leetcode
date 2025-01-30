class Solution {
   private:
    int sumByD(vector<int> &nums, int div) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += ceil((double)nums[i] / (double)div);
        }
        return sum;
    }

   public:
    int smallestDivisor(vector<int> &nums, int limit) {
        int n = nums.size();
        if (n > limit) return -1;

        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans=high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sumByD(nums, mid) <= limit) {
                ans=mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};