class Solution {
public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        auto check = [](vector<vector<int>> A) -> bool {
            int res = 0;
            sort(A.begin(), A.end());
            int pre = A[0][1];
            for (auto& ab : A) {
                int a = ab[0], b = ab[1];
                res += pre <= a;
                pre = max(pre, b);
            }
            return res > 1;
        };

        vector<vector<int>> X, Y;
        for (auto& r : rectangles) {
            X.push_back({r[0], r[2]});
            Y.push_back({r[1], r[3]});
        }
        return check(X) || check(Y);
    }
};