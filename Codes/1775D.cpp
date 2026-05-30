#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> spf;
void spf_SieveOfEratosthenes(int n) {
    spf = vector<int>(n + 1);
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= n; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int u, v;
    cin >> u >> v;
    --u;
    --v;

    vector<vector<int>> adj(6e5 + 10);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            int p = spf[x];
            adj[i].push_back(n + p);
            adj[n + p].push_back(i);
            while (x % p == 0) {
                x /= p;
            }
        }
    }

    vector<int> par(6e5 + 10, -1);
    vector<bool> vis(6e5 + 10);
    queue<int> q;

    q.push(u);
    vis[u] = true;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == v) {
            break;
        }
        for (int x : adj[curr]) {
            if (!vis[x]) {
                vis[x] = true;
                par[x] = curr;
                q.push(x);
            }
        }
    }

    if (!vis[v]) {
        cout << -1 << '\n';
        return;
    }

    vector<int> path;
    for (int cur = v; cur != -1; cur = par[cur]) {
        if (cur < n) {
            path.push_back(cur);
        }
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << " \n"[i == path.size() - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    spf_SieveOfEratosthenes(3e5 + 10);
    solve();
    return 0;
}
