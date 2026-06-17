#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(1);

    char curr = s[0];
    int segs = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == curr) {
            a.back()++;
        }
        else {
            a.push_back(1);
            curr ^= 1;
        }
    }

    int m = a.size(), cost = 0;
    vector<int> odds;
    for (int i = 0; i < m; i++) {
        if (a[i] % 2) {
            odds.push_back(i);
        }
    }

    int sz = odds.size();
    for (int i = 0; i + 1 < sz; i += 2) {
        cost += odds[i + 1] - odds[i];
    }

    curr = '$';
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            if (curr != '$' && curr != s[i]) {
                segs++;
            }
            curr = s[i];
        }
    }

    cout << cost + (sz % 2 ? odds[sz - 1] - odds[sz - 2] : 0) << ' ' << segs << '\n';
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
