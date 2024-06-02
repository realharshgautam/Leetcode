class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseHelper(s, 0, s.size() - 1);
    }
    
private:
    void reverseHelper(vector<char>& s, int left, int right) {
        if (left >= right) return;
        
        swap(s[left], s[right]);
        reverseHelper(s, left + 1, right - 1);
    }
};