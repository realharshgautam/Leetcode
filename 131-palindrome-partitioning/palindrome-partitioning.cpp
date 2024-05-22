class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Initialize the DP table for single characters and pairs
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                if (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result, dp);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result, const vector<vector<bool>>& dp) {
        // If we've reached the end of the string, add the current partition to the result list
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
        // Explore all possible partitions
        for (int end = start; end < s.length(); ++end) {
            // Use the DP table to check if the substring s[start:end+1] is a palindrome
            if (dp[start][end]) {
                path.push_back(s.substr(start, end - start + 1));
                // Recur to find other partitions
                backtrack(s, end + 1, path, result, dp);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }
};
