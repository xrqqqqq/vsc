#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 10;
int n, m, k;
int f[N], nf[N];
int mod = 1e9 + 7;
int fix(const int x) { return (x % mod + mod) % mod; }
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = fix(res * a);
        a = fix(a * a);
        b >>= 1;
    }
    return res;
}
int C(int a, int b) { return f[a] * nf[b] % mod * nf[a - b] % mod; }
void solve() {
    int r1, r2, c1, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int ans = 0;
    for (int j = c1; j <= c2; ++j) {
        int b = r1;
        int n = r2 - r1;
        int a = b + j;
        int tem = fix(C(a + n + 1, n + b) - C(a, b - 1));
        ans = fix(ans + tem);
    }
    cout << ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 3e6;
    f[0] = nf[0] = 1;
    f[1] = nf[1] = 1;
    for (int i = 2; i <= n; ++i) {
        f[i] = fix(f[i - 1] * i);
    }
    nf[n] = ksm(f[n], mod - 2);
    for (int i = n - 1; i >= 2; --i) {
        nf[i] = fix(nf[i + 1] * (i + 1));
    }
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}