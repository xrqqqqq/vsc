#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n, m, k;
int f[N];
int nf[N];
int mod = 998244353;
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int sum[N];
int C(int a,int b) {
    return f[a]*nf[b]%mod*nf[a-b]%mod;
}
void solve() {
    cin >> n;
    int a, b;
    cin >> a >> b;
    cin >> k;
    f[0] = nf[0] = f[1] = nf[1] = 1;
    for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] * i) % mod;
    nf[n] = ksm(f[n], mod - 2);
    for (int i = n - 1; i >= 2; --i) {
        nf[i] = (nf[i + 1] * (i + 1)) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int su = a * i;
        if (su <= k && (k - su) % b == 0) {
            int ii = (k - su) / b;
            int res = C(n,i)*C(n,ii)%mod;
            ans = (ans + res) % mod;
        }
    }
    cout << ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}