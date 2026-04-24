#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> par(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
    }

    vector<vector<int>> adj(n + 1);

    vector<int> score(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }

    for (int i = 2; i <= n; i++) {
        adj[par[i]].push_back(i);
    }

    vector<vector<pair<int, int>>> dp(n + 1);

    function<int(int, int)> dfs = [&](int u, int paths) -> int {
        if (paths == 0) {
            return 0;
        }

        for (auto [v, val] : dp[u]) {
            if (v == paths) {
                return val;
            }
        }

        int cnt = adj[u].size();
        if (cnt == 0) {
            return paths * score[u];
        }

        int ans = paths * score[u];
        vector<int> extra;
        int left = paths % cnt;
        int use = paths / cnt;

        for (auto x : adj[u]) {
            int pth1 = dfs(x, use);
            int pth2 = dfs(x, use + (left > 0));
            extra.push_back(pth2 - pth1);
            ans += pth1;
        }

        sort(extra.rbegin(), extra.rend());
        for (int i = 0; i < left; i++) {
            ans += extra[i];
        }

        dp[u].push_back({paths, ans});
        return ans;
    };

    cout << dfs(1, k) << '\n';
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
