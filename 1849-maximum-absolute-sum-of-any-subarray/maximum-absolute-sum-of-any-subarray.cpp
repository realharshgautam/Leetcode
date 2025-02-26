class Solution {
public:
    int maxAbsoluteSum(vector<int>& A) {
        int s = 0, mi = 0, ma = 0;
        for (int& a : A) {
            s += a;
            mi = min(mi, s);
            ma = max(ma, s);
        }
        return ma - mi;
    }
};