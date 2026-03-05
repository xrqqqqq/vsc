#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 998244353;
int n, m, k;
const int N = 5e5 + 10;
int a[N];
int c[N];
int ans;
int sxox[N][101];
int sxo[N][101];
int sx[N];
int fix(int x) { return (x % mod + mod) % mod; }
int la[N];
signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j != c[i]) {
                ans = fix(ans + sxox[la[j]][c[i]] * a[i] % mod);
                sxox[i][j] = sxox[la[c[i]]][j];
                sxox[i][j] = fix(sxox[i][j] + sxo[la[j]][c[i]] * a[i] % mod);
                sxo[i][j] = sxo[la[c[i]]][j];
                sxo[i][j] = fix(sxo[i][j] + sx[j] * a[i] % mod);
            }
        }
        sx[c[i]] = fix(sx[c[i]] + a[i]);
        la[c[i]] = i;
    }
    cout << fix(ans) << "\n";
}
