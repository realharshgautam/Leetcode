class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // Sort the vector in ascending order
        std::sort(happiness.begin(), happiness.end());

        // Reverse the vector to get descending order
        std::reverse(happiness.begin(), happiness.end());

        int selected = 0;
        long long happinessScore = 0; // Use long long to handle larger sums

        // Iterate over the sorted happiness values
        for (int score : happiness) {
            if (selected == k) {
                break; // Stop if 'k' elements have been selected
            }
            // Calculate and add the adjusted happiness value if it's positive
            happinessScore += std::max(0, score - selected);
            selected++;
        }

        return happinessScore;
    }
};