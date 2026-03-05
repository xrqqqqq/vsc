#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5e5 + 5, P = 998244353;  // g = 3

ll gg[30], ig[30], fac[N], ifac[N], inv[N];

ll qpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return ret;
}

void init() {
    gg[0] = ig[0] = 1;
    for (int i = 1; i < 30; ++i) gg[i] = qpow(3, (P - 1) / (1 << i));
    for (int i = 1; i < 30; ++i) ig[i] = qpow(gg[i], P - 2);
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        inv[i] = (i == 1) ? 1 : -(P / i) * inv[P % i] % P;  // 1/i
        fac[i] = fac[i - 1] * i % P;
    }
    ifac[N - 1] = qpow(fac[N - 1], P - 2);
    for (int i = N - 1; i >= 1; --i) {
        ifac[i - 1] = ifac[i] * i % P;
    }
}

int rev[N];

void ntt(ll *a, int tot, int ty) {
    for (int i = 0; i < tot; ++i) {
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    int t = 1;
    for (int mid = 1; mid < tot; mid <<= 1, ++t) {
        ll g1 = gg[t];
        if (ty == -1) {
            g1 = ig[t];
        }
        for (int i = 0; i < tot; i += mid * 2) {
            ll gk = 1;
            for (int j = 0; j < mid; ++j, gk = gk * g1 % P) {
                ll x = a[i + j], y = a[i + j + mid];
                a[i + j] = (x + gk * y) % P;
                a[i + j + mid] = (x - gk * y) % P;
            }
        }
    }
    if (ty == -1) {
        ll tmp = qpow(tot, P - 2);
        for (int i = 0; i < tot; ++i) {
            a[i] = a[i] * tmp % P;
        }
    }
}

void polymul(ll *f, const ll *g, const ll *h, int n, int m) {  // 项数，非次数
    static ll a[N], b[N];
    int tot = 1, bit = 0;
    while (tot < n + m - 1) ++bit, tot <<= 1;
    for (int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit - 1);
    memcpy(a, g, n * 8), memset(a + n, 0, (tot - n) * 8);
    memcpy(b, h, m * 8), memset(b + m, 0, (tot - m) * 8);
    ntt(a, tot, 1), ntt(b, tot, 1);
    for (int i = 0; i < tot; ++i) a[i] = a[i] * b[i] % P;
    ntt(a, tot, -1);
    memcpy(f, a, tot * 8);
}

void polyinv(ll *f, const ll *h, int n) {
    static ll d[N], g[N];
    int V = 1;
    while (V < n + n - 1) V <<= 1;
    memcpy(d, h, n * 8), memset(d + n, 0, (V - n) * 8);
    memset(f, 0, V * 8), memset(g, 0, V * 8);
    f[0] = qpow(h[0], P - 2);
    for (int w = 2; w / 2 < n; w <<= 1) {
        memcpy(g, d, w * 8);
        for (int i = 0; i < w * 2; ++i)
            rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? w : 0);
        ntt(f, w << 1, 1), ntt(g, w << 1, 1);
        for (int i = 0; i < w * 2; ++i) f[i] = (2 - f[i] * g[i]) % P * f[i] % P;
        ntt(f, w << 1, -1);
        memset(f + w, 0, w * 8);
    }
    memset(f + n, 0, (V - n) * 8);
}

void polysqrt(ll *f, const ll *h, int n) {
    static ll d[N], g[N], f_inv[N];
    int V = 1;
    while (V < n + n - 1) V <<= 1;
    memcpy(d, h, n * 8), memset(d + n, 0, (V - n) * 8);
    memset(f, 0, V * 8), memset(g, 0, V * 8), memset(f_inv, 0, V * 8);
    f[0] = 1;
    constexpr int i2 = 499122177;
    for (int w = 2; w / 2 < n; w <<= 1) {
        memcpy(g, d, w * 8);
        for (int i = 0; i < w * 2; ++i)
            rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? w : 0);
        polyinv(f_inv, f, w);
        ntt(f, w << 1, 1), ntt(g, w << 1, 1), ntt(f_inv, w << 1, 1);
        for (int i = 0; i < w * 2; ++i)
            f[i] = (f[i] + f_inv[i] * g[i]) % P * i2 % P;
        ntt(f, w << 1, -1);
        memset(f + w, 0, w * 8);
    }
    memset(f + n, 0, (V - n) * 8);
}

void polyder(ll *f, const ll *h, int n) {  // 项数，非次数
    for (int i = 0; i <= n - 1; ++i) {
        f[i] = (i + 1) * h[i + 1] % P;
    }
    f[n - 1] = 0;
}

void polyint(ll *f, const ll *h, int n) {  // 项数，非次数
    for (int i = n - 1; i >= 1; --i) {
        f[i] = h[i - 1] * inv[i] % P;
    }
    f[0] = 0;
}

void polyln(ll *f, const ll *h, int n) {  // h[0] = 1
    static ll a[N], b[N];
    polyinv(a, h, n);
    polyder(b, h, n);
    polymul(a, a, b, n, n);
    polyint(f, a, n);
}

void polyexp(ll *f, const ll *h, int n) {  // h[0] = 0
    static ll d[N], g[N], f_ln[N];
    int V = 1;
    while (V < n + n - 1) V <<= 1;
    memcpy(d, h, n * 8), memset(d + n, 0, (V - n) * 8);
    memset(f, 0, V * 8), memset(g, 0, V * 8), memset(f_ln, 0, V * 8);
    f[0] = 1;  // ln(h[0])
    for (int w = 2; w / 2 < n; w <<= 1) {
        memcpy(g, d, w * 8);
        for (int i = 0; i < w * 2; ++i)
            rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? w : 0);
        polyln(f_ln, f, w);
        ntt(f, w << 1, 1), ntt(g, w << 1, 1), ntt(f_ln, w << 1, 1);
        for (int i = 0; i < w * 2; ++i)
            f[i] = (1 - f_ln[i] + g[i]) % P * f[i] % P;
        ntt(f, w << 1, -1);
        memset(f + w, 0, w * 8);
    }
    memset(f + n, 0, (V - n) * 8);
}

void polypow(ll *f, ll *h, string K, int n) {
    int cur = 0;
    while (cur < n && h[cur] == 0) ++cur;
    ll k1 = 0, k2 = 0;
    for (auto ch : K) {
        if ((k1 * 10 + ch - '0') * cur >= n || cur == n) {
            for (int i = 0; i < n; ++i) f[i] = 0;
            return;
        }
        k1 = (k1 * 10 + ch - '0') % P;
        k2 = (k2 * 10 + ch - '0') % (P - 1);
    }

    ll h_cur = h[cur], icur = qpow(h_cur, P - 2);
    for (int i = cur; i < n; ++i) {
        f[i - cur] = h[i] * icur % P;
    }
    polyln(f, f, n - cur);
    for (int i = 0; i < n - cur; ++i) f[i] = f[i] * k1 % P;
    polyexp(f, f, n - cur);
    h_cur = qpow(h_cur, k2);
    for (int i = n - 1; i >= k1 * cur; --i) f[i] = f[i - k1 * cur] * h_cur % P;
    for (int i = 0; i < k1 * cur; ++i) f[i] = 0;
}
ll n, k, f[N];
ll c[N];
int m;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    cin >> n >> m;
    for(int i = 1;  i <= n ; ++i) {
        int x;
        cin>> x;
        c[x] = -4;
    }
    c[0] += 1;
    polysqrt(f,c,m + 1);
    f[0] += 1;
    polyinv(c,f,m+1);
    for(int i = 1;i <= m; ++i) {
        cout<< (2*c[i]%P + P) % P<<"\n";
    }
    return 0;
}