class Solution {
public:
        long long coloredCells(int n) {
        return 1l * n * n + 1l * (n - 1) * (n - 1);
    }
};