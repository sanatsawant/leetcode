class Solution {
    vector<int> merge(const vector<int>& a, const vector<int>& b, int B) {
        vector<int> c(B + 1, 0);
        for (int i = 0; i <= B; ++i)
            for (int j = 0; j <= i; ++j)
                c[i] = max(c[i], a[i - j] + b[j]);
        return c;
    }

public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {

        vector<vector<int>> g(n);
        for (auto &e : hierarchy)
            g[e[0] - 1].push_back(e[1] - 1);

        auto dfs = [&](auto&& self, int u) -> pair<vector<int>, vector<int>> {
            int cost = present[u], dCost = cost / 2;
            vector<int> sub0(budget + 1, 0), sub1(budget + 1, 0);

            for (int v : g[u]) {
                auto [c0, c1] = self(self, v);
                sub0 = merge(sub0, c0, budget);
                sub1 = merge(sub1, c1, budget);
            }

            vector<int> dp0(budget + 1, 0), dp1(budget + 1, 0);
            for (int i = 0; i <= budget; ++i) {
                dp0[i] = dp1[i] = sub0[i];
                if (i >= dCost)
                    dp1[i] = max(dp1[i], sub1[i - dCost] + future[u] - dCost);
                if (i >= cost)
                    dp0[i] = max(dp0[i], sub1[i - cost] + future[u] - cost);
            }
            return {dp0, dp1};
        };

        return dfs(dfs, 0).first[budget];
    }
};