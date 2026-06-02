#include <bits/stdc++.h>
using namespace std;

#define int long long

// Segment Tree (Range Max)
// Used to perform Range Max Queries and updates.
class SegmentTree_Max {
public:
    int n;
    vector<long long> tree;

    SegmentTree_Max(int n) : n(n) {
        tree.assign(4 * n, -1e18);
    }

    // Build the tree from an array
    // Time Complexity: O(n)
    void build(const vector<long long> &a, int node, int start, int end) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(a, node * 2, start, mid);
        build(a, node * 2 + 1, mid + 1, end);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    // Query max in range [l, r]
    // Time Complexity: O(log n)
    long long query(int node, int start, int end, int l, int r) {
        if (l > r) return -1e18;
        if (l == start && r == end) return tree[node];
        int mid = (start + end) / 2;
        return max(
            query(node * 2, start, mid, l, min(r, mid)),
            query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r)
        );
    }
};


map<int, set<int>> mpp;

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    mpp.clear();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mpp[a[i]].insert(i);
    }
    
    SegmentTree_Max st(n);
    st.build(a, 1, 0, n - 1);

    auto check = [&](auto& check, int l, int r) -> int {
        if (l >= r) {
            return 0;
        }
        
        int mx = st.query(1, 0, n - 1, l, r);
        int idx = *mpp[mx].lower_bound(l);
        return min(idx - l + check(check, idx + 1, r), r - idx + check(check, l, idx - 1));
    };

    cout << check(check, 0, n - 1) << '\n';
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
