class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> count(201, 0);
        for (int num : nums) {
            count[num + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (count[a + 100] == count[b + 100])
                return a > b;
            return count[a + 100] < count[b + 100];
        });
        return nums;
    }
};