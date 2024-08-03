static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;
        for(int& x : nums)  cnt += x;

        if(cnt == n)    return 0;

        int swaps = n;

        int l = 0;
        int r = 0;
        int curr = 0;

        while(l < n)
        {
            while(r >= l ? r - l < cnt : n - l + r < cnt)
            {
                curr += nums[r];
                r = (r + 1) % n;
            }

            swaps = min(swaps, cnt - curr);
            curr -= nums[l];
            l++;
        }

        return swaps;
    }
};