#include <bits/stdc++.h>
using namespace std;

// Policy Based Data Structures (PBDS)
#undef int // disables above #define int ll temporarily
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define int long long

using namespace __gnu_pbds;

// Ordered Set
// Use find_by_order(k) to get an iterator to the k-th (0-indexed) smallest element
// Use order_of_key(k) to get count of elements < x
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered multiset (allow duplicates) - store (value, unique_id)
// Use emplace({val, unique_id}) and order_of_key({x+1, MIN_ID}) to count <= x
template <typename T>
using ordered_multiset = tree< pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;

// Ordered map (order statistics on keys)
// Use find_by_order(k) to get k-th key; order_of_key(key) counts keys < key
template <typename Key, typename Mapped>
using ordered_map = tree< Key, Mapped, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

// gp_hash_table (fast hash map) - similar API to unordered_map
// Example: gp_hash_table<long long,int> gph;
template <typename K, typename V>
using gp_hash_table = cc_hash_table<K, V>;

/*
Quick usage notes:
- ordered_set<int> os; os.insert(x); os.order_of_key(x); os.find_by_order(k);
- ordered_multiset<long long> oms; int uid=0; oms.insert({val, uid++}); oms.order_of_key({val+1, PAIR_MIN});
- ordered_map<Key,Value> om; om.insert({k,v}); om.order_of_key(k);
- gp_hash_table<K,V> gph; gph.emplace(k,v); gph.find(k);
*/
#define int long long

void solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> mpp;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mpp[a[i]]++;
    }

    for (auto [x, y] : mpp) {
        if (y > 1) {
            cout << "YES\n";
            return;
        }
    }

    ordered_set<int> os;
    os.insert(a[n - 1]);
    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        ans += os.order_of_key(a[i]);
        os.insert(a[i]);
    }

    cout << (ans % 2 ? "NO\n" : "YES\n");
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
