#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n;
    cin >> n;
    
    vector<array<int,2>> a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i][0] = l, a[i][1] = r;
    }

    int ans = 0;
    vector<int> preL(n), preR(n), suffL(n), suffR(n);
    preL[0] = a[0][0], preR[0] = a[0][1], suffL[n - 1] = a[n - 1][0], suffR[n - 1] = a[n - 1][1];

    for (int i = 1; i < n; i++) {
        preL[i] = max(preL[i - 1], a[i][0]);
        preR[i] = min(preR[i - 1], a[i][1]);
    }
    
    for (int i = n - 2; i >= 0; i--) {
        suffL[i] = max(suffL[i + 1], a[i][0]);
        suffR[i] = min(suffR[i + 1], a[i][1]);
    }

    for (int i = 0; i < n; i++) {
        int newL, newR;
        if (i == 0) {
            newL = suffL[1];
            newR = suffR[1];
        } else if (i == n - 1) {
            newL = preL[n - 2];
            newR = preR[n - 2];
        } else {
            newL = max(preL[i - 1], suffL[i + 1]);
            newR = min(preR[i - 1], suffR[i + 1]);
        }

        ans = max(ans, max(0LL, newR - newL));
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
    return 0;
}
