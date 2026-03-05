#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
bitset<N> v;
int L[60][N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v[i] = 0;
    }
    for (int i = 0; i < 60; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((a[j] >> i) & 1ll) {
                L[i][j] = 1;
            }
            L[i][j] += L[i][j - 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int rr = 1e18;
        for (int j = 0; j < 60; ++j) {
            int l = i, r = n;
            while (l < r) {
                int m = l + r + 1 >> 1;
                if (L[j][m] - L[j][i-1] <= 1) {
                    l = m;
                } else {
                    r = m - 1;
                }
            }
            rr = min(rr, l);
        }
        ans += rr - i + 1;
    }
    cout << ans << "\n";
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