class Solution {
public:
    int findContentChildren(vector<int>& students, vector<int>& cookies) {
        int n = students.size();
        int m = cookies.size();

        sort(students.begin(), students.end());
        sort(cookies.begin(), cookies.end());

        int l = 0, r = 0;
        while (l < n && r < m) {
            if (cookies[r] >= students[l]) l++;
            r++;
        }
        return l;
    }
};