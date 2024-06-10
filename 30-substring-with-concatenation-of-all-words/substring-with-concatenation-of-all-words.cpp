#define pb push_back
const int MOD = 1e9 + 7;
const int st = 2137;
int tab[10005], req[5005];
class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        set<pair<int, int>> zb;  // hash dictionary
        int t = 0, m = (int)words[0].size(), n = (int)words.size();
        for (int i = 0; i < n + 2; i++) req[i] = 0;              // cleaning
        for (int i = 0; i < (int)s.size() + 3; i++) tab[i] = 0;  // cleaning
        sort(words.begin(), words.end());                        // lexicographic sorting
        for (int i = 0; i < (int)words.size(); i++) {
            if (i && words[i] == words[i - 1]) {
                req[t]++;
                continue;
            }
            t++;
            req[t]++;
            int hs = 0;
            string v=words[i];
            for (int j = 0; j < (int)v.size(); j++) {
                hs = ((long long)hs * st + (int)v[j]) % MOD;
            }
            zb.insert({hs, t});//create dictionary
        }
        for (int i = 0; i < (int)s.size() - m + 1; i++) {
            int hs = 0;
            for (int j = i; j < i + m; j++) {
                hs = ((long long)hs * st + (int)s[j]) % MOD;
            }
            auto it = zb.lower_bound({hs, 0});
            if ((*it).first == hs) tab[i] = (*it).second;  // marking words
        }
        for (int i = 0; i < min(m, (int)s.size() - n * m + 1); i++) {
            map<int, int> pm;
            int res = 0;
            for (int j = i; j < i + n * m; j += m) {  // two pointers strategy preprocessing
                if (tab[j]) {
                    pm[tab[j]]++;
                    if (pm[tab[j]] == req[tab[j]]) res++;
                }
            }
            if (res == t) ans.pb(i);
            for (int j = i + m; j < (int)s.size() - n * m + 1; j += m) {  // two pointers strategy
                if (tab[j - m]) {
                    if (pm[tab[j - m]] == req[tab[j - m]]) res--;
                    pm[tab[j - m]]--;
                }
                if (tab[j + (n - 1) * m]) {
                    pm[tab[j + (n - 1) * m]]++;
                    if (pm[tab[j + (n - 1) * m]] == req[tab[j + (n - 1) * m]]) res++;
                }
                if (res == t) ans.pb(j);
            }
        }
        return ans;
    }
};