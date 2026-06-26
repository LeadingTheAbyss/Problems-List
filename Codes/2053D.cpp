#include <bits/stdc++.h>
using namespace std;

/*
    Modular Arithmetic Operations (ModInt)
    Source :
        - https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/number-theory%20(11.1)/Modular%20Arithmetic/ModInt.h
*/

#pragma once
const int mod = 1e9 + 7; // 998244353
// primitive root for FFT (if you need it)
const int primitive_root = 5;

struct Mint {
    int x;
    explicit operator int() const { return x; }
    Mint(): x(0) {}
    Mint(long long y) {
        x = int((-mod < y && y < mod) ? y : y % mod);
        if (x < 0) x += mod;
    }
    bool operator==(const Mint& o) const { return x == o.x; }
    friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
    friend bool operator<(const Mint& a, const Mint& b) { return a.x < b.x; }

    // Addition assignment (modular)
    // Time Complexity: O(1)
    Mint& operator+=(const Mint& o) {
        if ((x += o.x) >= mod) x -= mod;
        return *this;
    }

    // Subtraction assignment (modular)
    // Time Complexity: O(1)
    Mint& operator-=(const Mint& o) {
        if ((x -= o.x) < 0) x += mod;
        return *this;
    }

    // Multiplication assignment (modular)
    // Time Complexity: O(1)
    Mint& operator*=(const Mint& o) {
        x = int((long long)x * o.x % mod);
        return *this;
    }

    // Division assignment (modular): multiply by inverse
    // Time Complexity: O(log mod) due to pow in inv
    Mint& operator/=(const Mint& o) { return (*this) *= inv(o); }

    // Fast exponentiation: a^p (p >= 0)
    // Time Complexity: O(log p)
    friend Mint pow(Mint a, long long p) {
        assert(p >= 0);
        Mint ans = 1;
        while (p > 0) {
            if (p & 1) {
                ans *= a;
            }
            a *= a;
            p >>= 1;
        }
        return ans;
    }

    // Multiplicative inverse using Fermat (mod must be prime)
    // Time Complexity: O(log mod)
    friend Mint inv(const Mint& a) {
        assert(a.x != 0);
        return pow(a, mod - 2);
    }
    Mint operator-() const { return Mint(-x); }
    Mint& operator++() { return *this += 1; }
    Mint& operator--() { return *this -= 1; }
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend ostream &operator<<(ostream &out, const Mint &a) {
        return out << a.x;
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c = a, d = b;
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    Mint prod = 1;
    for (int i = 0; i < n; i++) {
        prod *= min(c[i], d[i]);
    }

    cout << prod;
    for (int i = 0; i < q; i++) {
        int o, x;
        cin >> o >> x;
        --x;

        if (o == 1) {
            a[x]++;
            int idx = lower_bound(c.begin(), c.end(), a[x]) - c.begin() - 1;
            prod /= Mint(min(c[idx], d[idx]));
            c[idx]++;
            prod *= Mint(min(c[idx], d[idx]));
        }
        else {
            b[x]++;
            int idx = lower_bound(d.begin(), d.end(), b[x]) - d.begin() - 1;
            prod /= Mint(min(c[idx], d[idx]));
            d[idx]++;
            prod *= Mint(min(c[idx], d[idx]));
        }

        cout << " " << prod;
    }

    cout << "\n";
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
