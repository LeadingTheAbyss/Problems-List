#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int r, g, b;
    cin >> r >> g >> b;

    vector<int> x = {r, g, b};
    sort(x.begin(), x.end());

    int y = x[0] + x[1];
    if (y * 2 <= x[2]) {
        cout << y << endl;
    }
    else {
        cout << (r + g + b) / 3 << endl;    
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
