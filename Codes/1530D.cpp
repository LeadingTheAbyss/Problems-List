#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    map<int, int> mpp;
    vector<int> free, bad;

    for (int i = 1; i <= n; i++) {
        if (mpp.count(a[i])) {
            bad.push_back(i);
        } else {
            mpp[a[i]] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!mpp.count(i)) {
            free.push_back(i);
        }
    }

    for (int i = 0; i < bad.size(); i++) {
        b[bad[i]] = free[i];
    }

    vector<int> same;
    for (int i = 1; i <= n; i++) {
        if (b[i] == i) {
            same.push_back(i);
        }
    }

    if (same.size() > 1) {
        for (int i = 0; i < same.size(); i++) {
            b[same[i]] = same[(i + 1) % same.size()];
        }
    } else if (same.size() == 1) {
        for (int i = 1; i <= n; i++) {
            if (i != same[0] and b[i] == a[same[0]]) {
                swap(b[same[0]], b[i]);
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            ans++;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
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
