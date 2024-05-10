class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Custom comparator for min-heap
        auto comp = [&arr](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };

        // Priority queue (min-heap)
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(comp)>
            pq(comp);

        // Initialize the heap with the first fraction of each numerator
        for (int i = 0; i < arr.size() - 1; ++i) {
            pq.emplace(i, arr.size() - 1);
        }

        // Binary search to find the next smaller denominator
        for (int i = 1; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            int numeratorIndex = top.first;
            int denominatorIndex = top.second;

            // Push the next smaller denominator for the current numerator
            if (denominatorIndex - 1 > numeratorIndex) {
                pq.emplace(numeratorIndex, denominatorIndex - 1);
            }
        }

        // Return the k-th smallest fraction
        auto result = pq.top();
        return {arr[result.first], arr[result.second]};
    }
};
