class Solution {
public:
    long long no(const vector<int>& v, long long n) {
        long long ans = 1, sum = 0;
        for (int weight : v) {
            if (sum + weight > n) {
                sum = weight;
                ans++;
            } else {
                sum += weight;
            }
        }
        return ans;
    }

    int shipWithinDays(const vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(), weights.end());
        long long high = accumulate(weights.begin(), weights.end(), 0LL);
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (no(weights, mid) <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return static_cast<int>(low);
    }
};