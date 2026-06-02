#include <bits/stdc++.h>
using namespace std;

#define int long long

class CartesianTree {
public:
    int n, root;
    vector<int> l, r; // nearest greater on left/right
    vector<array<int,2>> adj; // adj[u][0] = left child, adj[u][1] = right child
    vector<vector<int>> up; // binary lifting table for LCA
    vector<int> depth, sz, dp;                      

    CartesianTree(const vector<int> &a) : n(a.size()), l(n), r(n), adj(n, {-1,-1}), depth(n), sz(n), dp(n) {
        buildTree(a); // O(n)
    }

    int check() {
        dfs(root);
        return dp[root];
    }

private:
    // Build the tree using nearest greater element method
    // Time Complexity: O(n)
    void buildTree(const vector<int> &a) {
        for (int i = 0; i < n; i++) {
            l[i] = i - 1;
            while (l[i] >= 0 && a[l[i]] <= a[i]) l[i] = l[l[i]];
        }
        for (int i = n - 1; i >= 0; i--) {
            r[i] = i + 1;
            while (r[i] < n && a[r[i]] < a[i]) r[i] = r[r[i]];
        }
        for (int i = 0; i < n; i++) {
            if (l[i] == -1 && r[i] == n) {
                root = i;
            } else if (l[i] == -1) {
                adj[r[i]][0] = i;
            } else if (r[i] == n) {
                adj[l[i]][1] = i;
            } else if (a[l[i]] <= a[r[i]]) {
                adj[l[i]][1] = i;
            } else {
                adj[r[i]][0] = i;
            }
        }
    }

    // DFS to compute depth and 2^k ancestors for LCA
    // Time Complexity: O(n log n)
    void dfs(int u) {
        int lsz = 0, rsz = 0, ld = 0, rd = 0;

        if (adj[u][0] != -1) {
            dfs(adj[u][0]);
            lsz = sz[adj[u][0]];
            ld = dp[adj[u][0]];
        }

        if (adj[u][1] != -1) {
            dfs(adj[u][1]);
            rsz = sz[adj[u][1]];
            rd = dp[adj[u][1]];
        }

        sz[u] = 1 + lsz + rsz;
        dp[u] = min(lsz + rd, rsz + ld);
    }
};

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    CartesianTree ct(a);
    cout << ct.check() << '\n';
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
