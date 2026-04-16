#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define debug(...) do {} while(0)
#endif

#define int long long

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int,int, less<>> mpp;
    multiset<array<int,2>> ms;
    for (int x : a) {
        mpp[x]++;
    }
    
    int A = 0, B = 0, k = 0;   
    for (auto [x, y] : mpp) {
        if (k == 0) {
            A += (x + 1) / 2 * y;
            B += x / 2 * y;
        }
        else {
            B += (x + 1) / 2 * y;
            A += x / 2 * y;
        }
        k ^= 1;
    }
    
    cout << A << " " << B << '\n';
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
