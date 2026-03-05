#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int  sum[N], pre[N], suf[N];
int fac[N], finv[N];
int modpow(int x, int n, int p) {
    int res = 1;
    for (; n; x = 1ll * x * x % p, n >>= 1)
        if (n & 1) res = 1ll * res * x % p;
    return res;
}
int cal(int *f, int mx, int n)  // 已知f[0]到f[mx] 求f[n] 注意n的范围
{
    if (n <= mx) return f[n];
    int ans = 0;
    pre[0] = suf[mx] = 1;
    for (int i = 1; i <= mx; ++i)
        pre[i] = 1ll * (n - i + 1) % mod * pre[i - 1] %
                 mod;  // 注意到(n-i+1)*pre[i-1]在有些题可能爆ll 先%
    for (int i = mx; i >= 1; --i)
        suf[i - 1] = 1ll * (n - i) % mod * suf[i] % mod;
    for (int i = 0; i <= mx; ++i) {
        int sg = (mx - i) & 1 ? -1 : 1;
        ans = ans + 1ll * sg * pre[i] % mod * suf[i] % mod * finv[i] % mod *
                        finv[mx - i] % mod * f[i] % mod;
        if (ans >= mod) ans -= mod;
        if (ans < 0) ans += mod;
    }
    return ans;
}
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
    finv[N - 1] = modpow(fac[N - 1], mod - 2, mod);
    for (int i = N - 1; i >= 1; --i) finv[i - 1] = 1ll * finv[i] * i % mod;
}
int n,k;
int su[N];

void solve() {
    cin>>n>>k;
    for(int i = 0; i <= k + 1; ++i) {
        int tem = modpow(i,k,mod);
        if(i == 0) tem = 0;
        su[i] = (su[i- 1 < 0 ? 0 : i - 1] + tem) % mod;
    }
    cout<<cal(su,k + 1,n);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     init();
    int T = 1;
    solve();
}