class Solution {
public:
       int countPairs(vector<int>& A, int low, int high) {
        return test(A, high + 1) - test(A, low);
    }

    int test(vector<int>& A, int x) {
        unordered_map<int, int> count, count2;
        for (int a : A) count[a]--;
        int res = 0;
        while (x) {
            for (auto const& [k, v] : count) {
                count2[k >> 1] += v;
                if (x & 1)
                    if (count.find((x - 1) ^ k) != count.end())
                        res += v * count[(x - 1) ^ k];
            }
            swap(count, count2);
            count2.clear();
            x >>= 1;
        }
        return res / 2;
    }
};