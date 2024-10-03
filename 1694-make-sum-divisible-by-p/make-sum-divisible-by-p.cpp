class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;  // Use long long to avoid overflow
        for (int num : nums) {
            totalSum += num;
        }
        int remainder = totalSum % p;

        // If the total sum is already divisible by p, return 0
        if (remainder == 0) {
            return 0;
        }

        return findSmallestSubarray(nums, p, remainder);
    }

private:
    int findSmallestSubarray(vector<int>& nums, int p, int remainder) {
        long long prefixSum = 0;  // Use long long to avoid overflow
        int minLength = nums.size();
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;  // Initial condition for no subarray

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int targetRemainder = (prefixSum % p - remainder + p) % p;

            if (prefixMap.find(targetRemainder) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[targetRemainder]);
            }

            prefixMap[prefixSum % p] = i;
        }

        return minLength < nums.size() ? minLength : -1;
    }
};