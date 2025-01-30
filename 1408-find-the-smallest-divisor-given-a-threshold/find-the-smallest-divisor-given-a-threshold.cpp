class Solution {
   private:
    int sumByD(vector<int> &nums, int div) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += ceil((double)nums[i] / (double)div);
        }
        return sum;
    }
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

   public:
    int smallestDivisor(vector<int> &nums, int limit) {
        int n = nums.size();
        if (n > limit) return -1;

        int low = 1, high = findMax(nums);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (sumByD(nums, mid) <= limit) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};