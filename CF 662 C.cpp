// https://codeforces.com/problemset/problem/662/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = int;
int n, m, k;
const int MAXN = (1 << 20) + 10;
int f[MAXN],p[MAXN];
const ll P = 998244353;
// 快速幂求逆元
ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

// 2的逆元，用于XOR变换
const ll inv2 = pow_mod(2, P - 2);

template <class T>
void and_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                if (is == 1) {
                    f[t1] = (u + v) % P;
                    f[t2] = v;
                } else {
                    f[t1] = (u - v + P) % P;
                    f[t2] = v;
                }
            }
        }
    }
}

template <class T>
void or_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                if (is == 1) {
                    f[t1] = u;
                    f[t2] = (v + u) % P;
                } else {
                    f[t1] = u;
                    f[t2] = (v - u + P) % P;
                }
            }
        }
    }
}

template <class T>
void xor_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                if (is == 1) {
                    f[t1] = (u + v) % P;
                    f[t2] = (u - v + P) % P;
                } else {
                    f[t1] = (u + v) * inv2 % P;
                    f[t2] = (u - v + P) * inv2 % P;
                }
            }
        }
    }
}

template <class T>
void andf(T f[], T g[], int n) {
    int ldn = __lg(n);
    and_fwt(f, ldn);
    and_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % P;
    and_fwt(f, ldn, -1);
}

template <class T>
void orf(T f[], T g[], int n) {
    int ldn = __lg(n);
    or_fwt(f, ldn);
    or_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % P;
    or_fwt(f, ldn, -1);
}

template <class T>
void xorf(T f[], T g[], int n) {
    int ldn = __lg(n);
    xor_fwt(f, ldn);
    xor_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = f[i] * g[i] % P;
    xor_fwt(f, ldn, -1);
}
string s[21];
void solve() {
    cin>>n>>m;
    for(int i = 0; i < n; ++i) cin>>s[i];
    for(int i = 0; i < m; ++i) {
        int res = 0;
        for(int j = 0; j < n; ++j) {
            res = res*2 + (s[j][i] - '0');
        }
        p[res]++;
    }
    for(int i = 0; i < (1 << n); ++i)
        f[i] =
            min(__builtin_popcount(i), __builtin_popcount(((1 << n) - 1) ^ i));
    xorf(p, f, 1 << n);
    int ans = 1e9;
    for(int i = 0; i < (1 << n); ++i)
        ans = min(ans, p[i]);
    cout<<ans<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}