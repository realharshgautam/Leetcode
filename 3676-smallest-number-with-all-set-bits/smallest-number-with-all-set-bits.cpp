class Solution {
public:
       

    int smallestNumber(int n) {
        return INT_MAX >> __builtin_clz(n) - 1;
    }
};