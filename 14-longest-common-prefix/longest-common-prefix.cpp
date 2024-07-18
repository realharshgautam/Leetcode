class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.empty()) return ans;

        int i = 0;
        while (true) {
            char curr_ch = 0;
            for (auto& str : strs) {
                if (i >= str.size()) return ans; // No common prefix if index exceeds string size
                
                if (curr_ch == 0) {
                    curr_ch = str[i];
                } else if (str[i] != curr_ch) {
                    return ans; // No common prefix if characters do not match
                }
            }
            ans.push_back(curr_ch);
            i++;
        }
    }
};
