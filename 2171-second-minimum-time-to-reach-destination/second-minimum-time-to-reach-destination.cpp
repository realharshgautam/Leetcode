inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
    static constexpr int howLong(int needed, int time, int change) {
        int ans = 0;
        for (int i = 0; i < needed; i++) {
            int turn = ans / change;
            if ((turn % 2) != 0)
                ans += change - (ans % change);

            ans += time;
        }
        return ans;
    }
public:
    static int secondMinimum(int N, const vector<vector<int>>& edges, int time,
                             int change) {
        std::vector<std::vector<int>> G(N);
        for (const auto& edge : edges) {
            G[edge[0] - 1].push_back(edge[1] - 1);
            G[edge[1] - 1].push_back(edge[0] - 1);
        }

        std::deque<int> Q;
        std::vector<char> seen(N * 2);
        Q.push_front(0);
        seen[0] = true;

        int maxLength = std::numeric_limits<int>::max();

        int wave = 0;
        bool odd = true;
        while (!Q.empty()) {
            const int thisRound = Q.size();
            odd = !odd;
            for (int i = 0; i < thisRound; i++) {
                auto pos = Q.front();
                Q.pop_front();

                if (pos == N - 1) {
                    if (maxLength == std::numeric_limits<int>::max()) {
                        maxLength = wave + 2;
                        continue;
                    } else {
                        maxLength = std::min(maxLength, wave);
                        return howLong(maxLength, time, change);
                    }
                }

                for (const auto next : G[pos]) {
                    if (seen[next * 2 + !odd])
                        continue;

                    seen[next * 2 + !odd] = true;
                    Q.push_back(next);
                }
            }
            wave++;

            if (maxLength < wave)
                break;
        }

        return howLong(maxLength, time, change);
    }
};
