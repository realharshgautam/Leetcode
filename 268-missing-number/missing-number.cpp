class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        int N = nums.size();

        // Use a single loop to compute both xor1 and xor2
        for (int i = 0; i < N; i++) {
            xor1 ^= (i + 1);  // XOR all indices from 1 to N
            xor2 ^= nums[i];  // XOR all elements in the array
        }

        // The missing number is the result of xor1 ^ xor2
        return xor1 ^ xor2;
    }
};
