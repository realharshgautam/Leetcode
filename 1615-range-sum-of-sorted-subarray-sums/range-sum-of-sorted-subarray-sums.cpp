class Solution {
public:
    static const int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sumSubarrays;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for (auto x : nums)
            sumSubarrays.push_back(x);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (i == 0)
                    sumSubarrays.push_back(prefix[j]);
                else
                    sumSubarrays.push_back(prefix[j] - prefix[i - 1]);
            }
        }
        sort(sumSubarrays.begin(), sumSubarrays.end());
        long long ans = 0;
        //(a+b)%c=( (a%c)+(b%c) )%c
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sumSubarrays[i]) % MOD;
        }
        return ans;
    }
};