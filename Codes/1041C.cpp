#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, m, d;
    cin >> n >> m >> d;
    vector<array<int,2>> a(n);
    vector<int> ans(n);
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        st.insert({a[i][0], i});
        a[i][1] = i;
    }

    sort(a.begin(), a.end());
    vector<bool> picked(n);
    int day = 1;
    for (int i = 0; i < n; i++) {
        if (picked[a[i][1]]) {
            continue;
        }
        ans[a[i][1]] = day;
        picked[a[i][1]] = true;
        int start = a[i][0];
        while (true) {
            auto lb = st.lower_bound({start + d + 1, -1});
            if (lb == st.end()) {
                break;
            }
            auto [min_time, idx] = *lb;
            ans[idx] = day;
            start = min_time;
            picked[idx] = true;
            st.erase({min_time, idx});
        }
        ++day;
    }

    cout << *max_element(ans.begin(), ans.end()) << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
