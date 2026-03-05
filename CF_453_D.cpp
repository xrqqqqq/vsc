#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
typedef long long ll;
const int MAXN = 1 << 20;
int P;
ll fix(const ll a) { return (a % P + P) % P; }
ll mul(const ll a, const ll b) {
    return fix(a * b - (ll)((long double)a / P * b) * P);
}
// 快速幂求逆元
ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}
// XOR FWT (任意模数版),n * mod <= 2^63
template <class T>
void xor_fwt(T f[], int ldn, int is = 1) {
    int n = 1 << ldn;
    for (int ldm = 1; ldm <= ldn; ++ldm) {
        int m = 1 << ldm, mh = m >> 1;
        for (int r = 0; r < n; r += m) {
            for (int j = 0; j < mh; ++j) {
                int t1 = r + j, t2 = r + j + mh;
                T u = f[t1], v = f[t2];
                f[t1] = (u + v) % P;
                f[t2] = (u - v + P) % P;
            }
        }
    }
    if (is == -1) {
        // 整体除以 n (保证能整除)
        for (int i = 0; i < n; ++i) {
            f[i] /= n;
            fix(f[i]);
        }
    }
}
// XOR 卷积 (注意：这里 f 的逆变换整体除以 n)
template <class T>
void xorf(T f[], T g[], int n) {
    int ldn = __lg(n);
    xor_fwt(f, ldn);
    xor_fwt(g, ldn);
    for (int i = 0; i < n; ++i) f[i] = mul(f[i],g[i]);
    xor_fwt(f, ldn, -1);
}
int m, t;
int c[MAXN], e[MAXN], cc[MAXN];
int f[21];
void solve() {
    cin >> m >> t >> P;
    int n = 1 << m;
    P *= n;
    for (int i = 0; i < n; i++) cin >> e[i];
    for (int i = 0; i <= m; ++i) cin >> f[i];
    c[0] = f[0];
    cc[0] = 0;
    for (int i = 1; i < n; ++i) {
        cc[i] = cc[i >> 1] + (i & 1);
        c[i] = f[cc[i]];
    }
    xor_fwt(c,m);
    for(int i = 0; i < n; ++i) {
        c[i] = pow_mod(c[i], t);
    }
    xor_fwt(c,m,-1);
    xorf(e, c, n);
    for (int i = 0; i < n; ++i) {
        cout << e[i]<< "\n";
    }
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