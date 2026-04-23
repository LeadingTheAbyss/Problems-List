#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> ranges(m);
    for (int i = 0; i < m; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
    }

    vector<int> cnt(n + 1), dp(n + 2), diff(n + 2), maxi(n + 2);
    for (auto [l, r] : ranges) {
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }

    vector<vector<int>> start(n + 1);
    for (auto [l, r] : ranges) {
        start[l].push_back(r);
    }

    priority_queue<int> pq; 
    for (int i = 1; i <= n; i++) {
        for (auto r : start[i]) {
            pq.push(r);
        }

        while (!pq.empty() && pq.top() < i) {
            pq.pop();
        }

        if (!pq.empty()) {
            maxi[i] = pq.top();
        } else {
            maxi[i] = i; 
        }
    }

    for (int i = n; i >= 1; i--) {
        dp[i] = dp[i + 1];

        if (cnt[i] > 0) {
            dp[i] = max(dp[i], cnt[i] + dp[maxi[i] + 1]);
        }
    }

    cout << dp[1] << '\n';
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
