#define sort(a) sort(begin(a), end(a))
#define opt() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        opt();
        int res = 0, j = 0, best = 0;
        vector<pair<int, int>> temp;
        for(int i = 0; i < worker.size(); ++i) {
            temp.push_back({difficulty[i], profit[i]});
        }

        sort(temp); sort(worker);
        for(int work : worker) {
            while(work >= temp[j].first && j < worker.size()) {
                best = max(best, temp[j++].second);
            }
            
            res += best;
        }

        return res;
    }
};