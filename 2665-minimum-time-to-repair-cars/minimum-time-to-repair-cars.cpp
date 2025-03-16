class Solution {
public:
        long long repairCars(vector<int>& A, int cars) {
        long long left = 1, right = 1L * A[0] * cars * cars;
        while (left < right) {
            long long mid = (left + right) / 2, cur = 0;
            for (int a : A)
                cur += int(sqrt(1.0 * mid / a));
            if (cur < cars)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};