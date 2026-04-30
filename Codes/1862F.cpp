#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int w, f, n;
    cin >> w >> f >> n;
    
    vector<int> s(n);
    for (int i = 0; i < n; i++) {   
        cin >> s[i];
    }
    
    int big = max(w, f);
    int small = min(w, f);

    sort(s.begin(), s.end());

    auto check = [&](int mid) {
        int A = mid * small, B = mid * big, sum = accumulate(s.begin(), s.end(), 0LL);
        if (sum > A + B) {
            return false;
        }

        bitset<1000005> dp;
        dp[0] = 1;

        for (int x : s) {
            dp |= (dp << x);
        }

        int st = max(0LL, sum - B), end = min(sum, A);

        for (int i = st; i <= end; i++) {
            if (dp[i]) {
                return true;
            }
        }
        return false;
    };

    int ans = 0, low = 0, high = (accumulate(s.begin(), s.end(), 0LL) + small - 1) / small; 

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
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
