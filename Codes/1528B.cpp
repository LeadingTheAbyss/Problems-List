#include <bits/stdc++.h>
using namespace std;

#pragma once
const int mod = 998244353;
struct Mint {
    int x;
    explicit operator int() const { return x; }
    Mint(): x(0) {}
    Mint(long long y) {
        x = int((-mod < y && y < mod) ? y : y % mod);
        if (x < 0) x += mod;
    }

    // Addition assignment (modular)
    // Time Complexity: O(1)
    Mint& operator+=(const Mint& o) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }
};

void solve() {

    int n;
    cin >> n;

    vector<Mint> ans(n + 1);

    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            ans[j] += 1;
        }
    }

    Mint res = 0;
    for (int i = 2; i <= n; i++) {
        res += ans[i - 1];
        ans[i] += res;
    }

    cout << (int)ans[n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
    return 0;
}
