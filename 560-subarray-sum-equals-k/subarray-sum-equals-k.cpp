class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> preSum; // To store prefix sums
        preSum[0] = 1; // Base case for subarray starting from index 0
        
        for (int num : nums) {
            sum += num; // Update cumulative sum

            // Check if (sum - k) exists in the map
            if (preSum.find(sum - k) != preSum.end()) {
                count += preSum[sum - k]; // Add the count of such prefix sums
            }

            // Update the frequency of the current sum in the map
            preSum[sum]++;
        }
        
        return count; // Return the total count of subarrays with sum = k
    }
};
