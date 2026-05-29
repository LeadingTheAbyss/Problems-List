#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> und(n + 1);
    vector<array<int, 2>> p(m + 1);
    vector<bool> edge_in(n + 1, false), edge_out(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        und[u].push_back(v);
        und[v].push_back(u);
        p[i] = {u, v};
    }

    queue<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    edge_in[1] = true;
    vis[1] = true;
    q.push({1, 0});
    
    while (!q.empty()) {
        auto [u, k] = q.front();
        q.pop();

        for (int x : und[u]) {
            if (!vis[x]) {
                vis[x] = true;
                if (k == 0) {
                    edge_out[x] = true;
                    q.push({x, 1});
                }
                else {
                    edge_in[x] = true;
                    q.push({x, 0});
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if ((edge_out[p[i][0]] and edge_out[p[i][1]]) or (edge_in[p[i][0]] and edge_in[p[i][1]])) {
            cout << "NO\n";
            return;
        }
        if (edge_out[p[i][0]]) {
            ans.push_back(1);
        }
        else {
            ans.push_back(0);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
