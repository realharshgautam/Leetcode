class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size() + 1;
        vector<int> prefix_xor(n, 0);
        for (int i = 1; i < n; i++) {
            prefix_xor[i] = prefix_xor[i - 1] ^ arr[i - 1];
        }

        int res = 0;

        for (int start = 0; start < n; start++) {
            for (int end = start + 1; end < n; end++) {
                if (prefix_xor[start] == prefix_xor[end]) {
                    res += end - start - 1;
                }
            }
        }

        return res;
    }
};