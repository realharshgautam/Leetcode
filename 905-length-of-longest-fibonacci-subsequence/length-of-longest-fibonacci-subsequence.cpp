class Solution {
public:
        int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                int  a = A[i], b = A[j], l = 2;
                while (s.count(a + b))
                    b = a + b, a = b - a, l++;
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};