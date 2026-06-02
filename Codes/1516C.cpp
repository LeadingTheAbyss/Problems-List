#include <bits/stdc++.h>
using namespace std;

#define int long long

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;
    if (totalSum % 2 != 0) return false;

    int targetSum = totalSum / 2;
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true;
    for (int num : nums) {
        for (int currSum = targetSum; currSum >= num; --currSum) {
            dp[currSum] = dp[currSum] || dp[currSum - num];
        }
    }
    return dp[targetSum];
}

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (!canPartition(a)) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            cout << "1\n";
            cout << i + 1 << '\n';
            return;
        }
    }

    vector<int> score(n, 0);
    int mini = 1e12;
    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            score[i]++;
        }
        mini = min(mini, score[i]);
    }

    auto idx = min_element(score.begin(), score.end());
    cout << "1\n" << (idx - score.begin() + 1) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
    return 0;
}
