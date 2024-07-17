class Solution {
public:
    string longestPalindrome(const std::string& s) {
        int n = s.length();
        if (n == 0) return "";

        int longest_palindrome_start = 0;
        int longest_palindrome_len = 1;

        for (int i = 0; i < n; ++i) {
            int right = i;
            while (right < n && s[i] == s[right]) {
                right++;
            }

            int left = i - 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            int palindrome_len = right - left - 1;
            if (palindrome_len > longest_palindrome_len) {
                longest_palindrome_len = palindrome_len;
                longest_palindrome_start = left + 1;
            }
        }

        return s.substr(longest_palindrome_start, longest_palindrome_len);
    }
};