class Solution {
public:
    int countSubstrings(const string& s) {
        int count = 0;
    int n = s.length();

    for (int i = 0; i < n; ++i) {
        // Expand around the center for odd-length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            ++count; // Count the palindrome
            --left;
            ++right;
        }

        // Expand around the center for even-length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            ++count; // Count the palindrome
            --left;
            ++right;
        }
    }

    return count;
    }
};