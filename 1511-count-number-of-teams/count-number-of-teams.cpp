class Solution {
public:
    int numTeams(vector<int>& ratings) {
        // Find the maximum rating
        int maxRating = 0;
        for (int rating : ratings) {
            maxRating = max(maxRating, rating);
        }

        // Initialize Binary Indexed Trees for left and right sides
        vector<int> leftBIT(maxRating + 1, 0);
        vector<int> rightBIT(maxRating + 1, 0);

        // Populate the right BIT with all ratings initially
        for (int rating : ratings) {
            updateBIT(rightBIT, rating, 1);
        }

        int teams = 0;
        for (int currentRating : ratings) {
            // Remove current rating from right BIT
            updateBIT(rightBIT, currentRating, -1);

            // Count soldiers with smaller and larger ratings on both sides
            int smallerRatingsLeft = getPrefixSum(leftBIT, currentRating - 1);
            int smallerRatingsRight = getPrefixSum(rightBIT, currentRating - 1);
            int largerRatingsLeft = getPrefixSum(leftBIT, maxRating) -
                                    getPrefixSum(leftBIT, currentRating);
            int largerRatingsRight = getPrefixSum(rightBIT, maxRating) -
                                     getPrefixSum(rightBIT, currentRating);

            // Count increasing and decreasing sequences
            teams += (smallerRatingsLeft * largerRatingsRight);
            teams += (largerRatingsLeft * smallerRatingsRight);

            // Add current rating to left BIT
            updateBIT(leftBIT, currentRating, 1);
        }

        return teams;
    }

private:
    // Update the Binary Indexed Tree
    void updateBIT(vector<int>& BIT, int index, int value) {
        while (index < BIT.size()) {
            BIT[index] += value;
            index +=
                index & (-index);  // Move to the next relevant index in BIT
        }
    }

    // Get the sum of all elements up to the given index in the BIT
    int getPrefixSum(vector<int>& BIT, int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & (-index);  // Move to the parent node in BIT
        }
        return sum;
    }
};