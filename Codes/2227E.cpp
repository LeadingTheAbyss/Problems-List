#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    vector<int> suff(n);
    suff[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = min(suff[i + 1], a[i]);
    }

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + suff[i];
    }

    int ans = total - pre[n];
    for (int k = 0; k < n; k++) {
        int x = a[k] - 1, l = upper_bound(suff.begin(), suff.begin() + k + 1, x) - suff.begin();
        int dec = 0;
        if (l <= k) {
            dec = pre[k + 1] - pre[l] - (k - l + 1) * x;
        }
        int cur = total - 1 - pre[n] + dec;
        ans = max(ans, cur);
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
