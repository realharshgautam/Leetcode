class Solution {
public:
    /**
     * Function to count the minimum number of subarrays required 
     * such that no subarray sum exceeds `maxSum`
     */
    int countSplits(vector<int> &nums, int maxSum) {
        int sum = 0, splits = 1;  // Start with 1 subarray

        for (int num : nums) {
            // If adding `num` exceeds `maxSum`, create a new subarray
            if (sum + num > maxSum) {
                splits++;  // Increase subarray count
                sum = num; // Reset sum for the new subarray
            } else {
                sum += num;  // Add element to current subarray
            }
        }
        return splits;
    }

    /**
     * Function to find the minimum largest sum possible when splitting the array into `m` subarrays
     */
    int splitArray(vector<int> &nums, int m) {
        int low = *max_element(nums.begin(), nums.end()); // Minimum possible max sum
        int high = accumulate(nums.begin(), nums.end(), 0); // Maximum possible sum (one subarray)

        // Binary search for the optimal max sum
        while (low <= high) {
            int mid = (low + high) / 2;
            int splits = countSplits(nums, mid); // Count required subarrays with maxSum = mid

            if (splits > m) {
                low = mid + 1;  // Increase max sum limit
            } else {
                high = mid - 1; // Try reducing max sum
            }
        }
        return low; // The smallest valid max sum
    }
};