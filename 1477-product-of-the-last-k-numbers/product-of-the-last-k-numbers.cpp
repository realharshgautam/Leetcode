class ProductOfNumbers {
public:
        vector<int> A = {1};
    void add(int a) {
        if (a)
            A.push_back(A.back() * a);
        else
            A = {1};
    }

    int getProduct(int k) {
        return k < A.size() ? A.back() / A[A.size() - k - 1]  : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */