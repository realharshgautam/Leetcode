class Solution {
public:
    int longestMonotonicSubarray(std::vector<int>& nums) {
        int incLength = 1, decLength = 1, maxLength = 1;

        for (size_t i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                incLength++;
                decLength = 1;
            } else if (nums[i + 1] < nums[i]) {
                decLength++;
                incLength = 1;
            } else {
                incLength = 1;
                decLength = 1;
            }
            maxLength = std::max(maxLength, std::max(incLength, decLength));
        }

        return maxLength;
    }
};