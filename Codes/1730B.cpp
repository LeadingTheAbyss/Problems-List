#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

void solve() {

    int n;
    cin >> n;
    vector<int> x(n), t(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    ld low = 0, high = 1e9, ans = 1e17;

    auto check = [&](ld m) {
        ld res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, t[i] + fabsl(m - x[i]));
        }
        return res;
    };

    while (high - low > 1e-6) {
        ld mid1 = low + (high - low) / 3;
        ld mid2 = high - (high - low) / 3;
        if (check(mid1) < check(mid2)) {
            high = mid2;
        } else {
            low = mid1;
        }
    }

    cout << fixed << setprecision(10) << low << '\n';
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
