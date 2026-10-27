/**
 *    created: 27-10-2026 17:45:51
**/

#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)
#include "debug.h"
#else
#define debug(...) do {} while(0)
#endif

#define int long long

int MAX_N = 1e5 + 10;
vector<int> phi(MAX_N);
void precompute() {
	for (int i = 1; i < MAX_N; i++) { phi[i] = i; }
	for (int i = 2; i < MAX_N; i++) {
		if (phi[i] == i) {
			for (int j = i; j < MAX_N; j += i) { phi[j] -= phi[j] / i; }
		}
	}
}

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    vector<int> d(1e5 + 10);
    for (int i = 0; i < n; i++) {
        unordered_map<int,int> mpp;
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0 and !mpp.count(j)) {
                ans += (d[j] * phi[j]) * (n - i - 1);
                d[j]++;
                mpp[j]++;
                if (!mpp.count(a[i] / j)) {
                    ans += (d[a[i] / j] * phi[a[i] / j] * (n - i - 1));
                    d[a[i] / j]++;
                }
            }
        }
    }

    cout << ans << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
