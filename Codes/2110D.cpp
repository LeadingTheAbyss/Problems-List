#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m;
    cin >> n >> m;
    vector<int> b(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<vector<array<int,2>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
    }

    auto check = [&](int k) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            if (dp[i] == 0 && i != 1) {
                continue;
            }
            dp[i] += b[i];
            dp[i] = min(dp[i], k);
            for (auto v : adj[i]) {
                if (v[1] <= dp[i]) {
                    dp[v[0]] = max(dp[v[0]], dp[i]);
                }
            }
        }
        return dp[n] > 0;
    };

    int low = 0, high = 1e18, ans = 1e18;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    solve();

    return 0;
}
