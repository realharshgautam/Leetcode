class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int x : nums) {
            if (x < k) {
                return -1;
            } else if (x > k) {
                st.insert(x);
            }
        }
        return st.size();
    }
};