#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int f(int x) { return (x % k + k) % k; }
void solve() {
    cin >> n;
    int mx = log2(n);
    cout << n * (mx + 1) << endl;
    for (int i = 0; i <= mx; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << j << " " << min(n, j + (1 << i) - 1) << endl;
        }
    }
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        int le = log2(r - l + 1);
        cout << l + le * n << " " << (r - (1 << le) + 1) + le * n << endl;
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