class Solution {
public:
    double myPow(double x, int n) {
        // Handle the case when n is negative
        long long power = n; // Use long long to handle edge case when n = INT_MIN
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        
        double result = 1.0;
        double current_product = x;

        // Exponentiation by squaring
        while (power > 0) {
            if (power % 2 == 1) { // If power is odd
                result *= current_product;
            }
            current_product *= current_product; // Square the current product
            power /= 2; // Halve the power
        }
        
        return result;
    }
};
