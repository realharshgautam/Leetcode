class Solution {
public:
    vector<std::string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> mapping;

        for (int i = 0; i < n; ++i) {
            mapping[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());

        for (int i = 0; i < n; ++i) {
            names[i] = mapping[heights[i]];
        }

        return names;
    }
};