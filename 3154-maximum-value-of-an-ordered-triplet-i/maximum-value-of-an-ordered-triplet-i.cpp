class Solution {
public:
        long long maximumTripletValue(vector<int>& A) {
        long long res = 0;
        int maxa = 0, maxab = 0;
        for (int&a : A) {   
            res = max(res, 1LL * maxab * a);
            maxab = max(maxab, maxa - a);
            maxa = max(maxa, a);
        }
        return res;
    }
};