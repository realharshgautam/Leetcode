class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;
        for(auto &q : queries) {
            int pos = q[0], c = q[1];
            if(ball.count(pos))
                if(--color[ball[pos]] == 0) distinct--;
            ball[pos] = c;
            if(++color[c] == 1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};