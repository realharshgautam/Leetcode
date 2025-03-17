class Solution {
public:
  bool divideArray(vector<int>& nums) {
    int cnt[501] = {};
    for (int n : nums)
        ++cnt[n];
    return all_of(begin(cnt), end(cnt), [](int cnt){ return cnt % 2 == 0; });
}
};