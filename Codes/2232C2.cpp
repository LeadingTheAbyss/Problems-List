#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, x, s;
    cin >> n >> x >> s;

    string p;
    cin >> p;

    int eT = x, eS = x * s, ans = 0, hold = 0;

    for (int i = 0; i < n; i++) {
        if (p[i] == 'I') {
            if (eT) {
                eT--;
                eS--;
                ans++;
            }
        }
        else if (p[i] == 'E') {
            if (eT * s < eS) {
                eS--;
                ans++;
            }
            else if (hold and eT) {
                eT--;
                eS--;
                hold--;
                ans++;
            }
        }
        else {
            if (eT * s < eS) {
                eS--;
                ans++;
                hold++;
            }
            else if (eT) {
                eT--;
                eS--;
                ans++;
            }
        }
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
