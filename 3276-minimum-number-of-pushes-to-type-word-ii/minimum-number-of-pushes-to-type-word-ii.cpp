class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> frequencyMap;

        // Count frequency of each character
        for (char c : word) {
            frequencyMap[c]++;
        }

        // Create a max heap based on character frequency
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second; // Max heap
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> maxHeap(cmp);

        for (const auto& entry : frequencyMap) {
            maxHeap.push(entry);
        }

        int count = 0;
        int j = 1;

        // Calculate minimum pushes based on character priority
        while (!maxHeap.empty()) {
            auto entry = maxHeap.top();
            maxHeap.pop();
            if (j <= 8) {
                count += entry.second;
            } else if (j > 8 && j <= 16) {
                count += entry.second * 2;
            } else if (j > 16 && j <= 24) {
                count += entry.second * 3;
            } else {
                count += entry.second * 4;
            }
            j++;
        }

        return count;
    }
};