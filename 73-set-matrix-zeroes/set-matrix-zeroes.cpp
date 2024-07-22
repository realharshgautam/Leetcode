class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows in the matrix
        int n = matrix[0].size(); // Number of columns in the matrix
        
        // Variable to track if the first column should be set to zero
        int col0 = 1;

        // First pass: Use the first row and first column as markers.
        // If an element is zero, mark the corresponding row and column.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    // Mark the ith row by setting the first element of the row to 0
                    matrix[i][0] = 0;
                    // Mark the jth column by setting the first element of the column to 0
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0; // Special marker for the first column
                }
            }
        }

        // Second pass: Set matrix elements to zero based on the markers
        // Start from 1 to avoid overwriting the markers prematurely
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row separately
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Handle the first column separately
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
