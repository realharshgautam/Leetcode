class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin(), pos = nums.end() - upper_bound(nums.begin(), nums.end(), 0); 
        return max(neg, pos); 
    }
};