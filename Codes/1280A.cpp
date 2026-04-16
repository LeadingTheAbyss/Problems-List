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
};

// small combinations table (nCk mod mod)
// scmb[n][k] == C(n,k) as modular integers
vector<vector<Mint>> scmb; // small combinations table

// Build Pascal's triangle up to n - 1
// Time Complexity: O(n^2)
void genComb(int n) {
    scmb.assign(n, vector<Mint>(n));
    if (n <= 0) return;
    scmb[0][0] = Mint(1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            Mint left = scmb[i - 1][j];
            Mint right = Mint(0);
            if (j > 0) {
                right = scmb[i - 1][j - 1];
            }
            scmb[i][j] = left + right;
        }
    }
}

void solve() {

    int x;
    string S;
    cin >> x >> S;
    
    Mint c = 0, s = S.length();
    int l = 0, n = S.length();

    while (l != x) {
        l += 1;
        c = s - l;
        s = l;
        s += c * (S[l - 1] - '0');
        
        if (S.length() < x) {
            string add = S.substr(l);
            for (int i = 1; i < (S[l - 1] - '0') and n < x; i++) {
                int need = x - S.length();
                if (add.length() <= need) {
                    S += add;
                }
                else {
                    S += add.substr(0, need);
                }
            }
        }
    }

    cout << (int)s << '\n';
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
