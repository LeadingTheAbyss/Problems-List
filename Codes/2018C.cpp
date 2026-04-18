#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> par(n + 1), dep(n + 1), val(n + 1), order;
    vector<vector<int>> level(n + 1);

    queue<int> q;
    q.push(1);
    par[1] = 0;
    dep[1] = 0;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        order.push_back(x);
        level[dep[x]].push_back(x);

        for (int u : adj[x]) {
            if (u != par[x]) {
                par[u] = x;
                dep[u] = dep[x] + 1;
                q.push(u);
            }
        }
    }

    int maxi = 0;

    for (int i = 1; i <= n; i++) {
        val[i] = dep[i];
        maxi = max(maxi, dep[i]);
    }

    reverse(order.begin(), order.end());

    for (int x : order) {
        for (int u : adj[x]) {
            if (u != par[x]) {
                val[x] = max(val[x], val[u]);
            }
        }
    }

    vector<int> removeOld(maxi + 10);

    for (int i = 1; i <= n; i++) {
        removeOld[val[i] + 1]++;
    }

    for (int i = 1; i <= maxi; i++) {
        removeOld[i] += removeOld[i - 1];
    }

    int deeper = n, ans = n;

    for (int d = 0; d <= maxi; d++) {
        for (int x : level[d]) {
            deeper--;
        }
        ans = min(ans, removeOld[d] + deeper);
    }

    cout << ans << '\n';
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
