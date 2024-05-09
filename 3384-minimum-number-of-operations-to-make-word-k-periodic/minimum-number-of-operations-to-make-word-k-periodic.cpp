class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string, int> freq;

        for (int i = 0; i < n; i += k) {
            string segment = word.substr(i, k);
            freq[segment]++;
        }

        int maxFreq = 0;
        for (const auto& p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        return (n / k) - maxFreq;
    }
};