#include <bits/stdc++.h>
using namespace std;
#define int long long
// const int N = 1e6 + 10;
int n, m, k;
using ll = long long;
constexpr int N = 2e6 + 5, P = 998244353;  // g = 3

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
                a[i + j + mid] = ((x - gk * y) % P + P) % P;
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
void polymul( ll *a, ll *b, int n, int m) {  // 项数，非次数
    int tot = 1, bit = 0;
    while (tot < n + m - 1) ++bit, tot <<= 1;
    for (int i = 0; i < tot; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << bit - 1);
    ntt(a, tot, 1), ntt(b, tot, 1);
    for (int i = 0; i < tot; ++i) a[i] = a[i] * b[i] % P;
    ntt(a, tot, -1);
}
int p[N],f[N],ff[N];
int w[] = {1,0,0,0,1,0,1,0,2,1};
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        x %= m;
        p[x]++;
    }
    f[0] = 1;
    for(int i = 1; i < m; ++i) {
        int x = i;
        int res = 0;
        while(x) {
            res += w[x % 10];
            x /= 10;
        }
        f[i] = res;
    }
    for(int i = 0; i <m; ++i) {
        ff[i] = f[(-i+m)%m];
    }
    for(int i = m; i < 2*m; ++i) {
        ff[i] = ff[i-m];
    }
    polymul(p,ff,m,2*m);
    int ans = 0;
    for(int i = 0; i < m; ++i) {
        ans = max(ans ,p[i+m]);
    }
    cout<<ans<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    init();
    // cin >> T;
    while (T--) {
        solve();
    }
}