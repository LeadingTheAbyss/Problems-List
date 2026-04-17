#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;
    string S, s = '.';
    cin >> S;
    s += S;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> cycles, vis(n + 1);

    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }

        vector<int> cyc;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;
            cyc.push_back(j);
            j = a[j];
        }

        string curr = "";
        for (int id : cyc) {
            curr += s[id];
        }

        int m = curr.size(), need = m;

        for (int k = 1; k <= m; k++) {
            if (m % k != 0) {
                continue;
            }

            bool ok = true;
            for (int x = 0; x < m; x++) {
                if (curr[x] != curr[(x + k) % m]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                need = k;
                break;
            }
        }

        cycles.push_back(need);
    }

    int l = 1;
    for (int x : cycles) {
        l = lcm(l, x);
    }

    cout << l << '\n';
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
