

class Solution {
private:
    // Recursive function to generate letter combinations
    void func(int ind, const string& digits, string s, vector<string>& ans,
              const string combos[]) {
        // Base case: if index reaches the end of digits, add the current
        // combination
        if (ind == digits.size()) {
            ans.push_back(s);
            return;
        }
        // Convert the current character to an integer (digit)
        int digit = digits[ind] - '0';
        // Loop through the corresponding characters for the current digit
        for (int i = 0; i < combos[digit].size(); i++) {
            // Recursively build the combination by adding the current letter
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        // Return an empty vector if the input is empty
        if (digits.empty()) {
            return {};
        }

        // Mapping digits to corresponding characters (index 0 and 1 are empty)
        string combos[] = {"",    "",    "abc",  "def", "ghi",
                           "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; // Vector to store the result
        string s = "";      // Temporary string to build combinations

        // Initiate recursive function starting from index 0
        func(0, digits, s, ans, combos);
        return ans; // Return the resulting combinations
    }
};
