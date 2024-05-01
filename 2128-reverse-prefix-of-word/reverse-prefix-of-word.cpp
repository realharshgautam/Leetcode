class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        if (j != -1) {
            reverse(word.begin(), word.begin() + j + 1);
        }
        return word;
    }
};