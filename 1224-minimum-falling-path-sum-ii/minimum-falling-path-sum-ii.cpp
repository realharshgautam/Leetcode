// Define the Triplet class
class Triplet {
public:
    int minSum;
    int secondMinSum;
    int minSumIndex;

    // Constructor for Triplet class
    Triplet(int minSum, int secondMinSum, int minSumIndex) {
        this->minSum = minSum;
        this->secondMinSum = secondMinSum;
        this->minSumIndex = minSumIndex;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        return minFallingPathSum(0, grid).minSum;
    }

private:
    Triplet minFallingPathSum(int row, vector<vector<int>>& grid) {
        // Base case: if the current row is beyond the grid's bounds, return a Triplet with zero sum
        if (row == grid.size()) {
            return Triplet(0, 0, 0);
        }

        // Recursively calculate the minimum falling path sum for the next row
        Triplet nextRowTriplet = minFallingPathSum(row + 1, grid);

        // Initialize the current row's Triplet with maximum values
        Triplet currentTriplet(INT_MAX, INT_MAX, -1);

        // Iterate through each column in the current row
        for (int col = 0; col < grid[0].size(); col++) {
            // Calculate the sum for choosing the current cell and the appropriate sum from the next row
            int sum = grid[row][col] + ((col != nextRowTriplet.minSumIndex) ? nextRowTriplet.minSum : nextRowTriplet.secondMinSum);

            // Update the currentTriplet with the minimum and second minimum sums and their indices
            if (sum <= currentTriplet.minSum) {
                currentTriplet.secondMinSum = currentTriplet.minSum;
                currentTriplet.minSum = sum;
                currentTriplet.minSumIndex = col;
            } else if (sum < currentTriplet.secondMinSum) {
                currentTriplet.secondMinSum = sum;
            }
        }

        return currentTriplet;
    }
};