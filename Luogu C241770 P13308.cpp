#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    unordered_map<int, int> d, fa;
    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (m--) {
        int op;
        cin >> op;
        int u;
        cin >> u;
        if (op == 2) {
            while (u > 1 && fa[u] == 0) {
                u >>= 1;
            }
            if (d.count(u) == 0) {
                d[u] = (1ll << (n - (int)log2(u))) - 1;
            }
            ans ^= d[u];
        } else {
            if (d.count(u) == 0) {
                d[u] = (1ll << (n - (int)log2(u))) - 1;
            }
            int last = u;
            u >>= 1;
            while (u  && fa[u] == 0) {
                if (d.count(u) == 0) {
                    d[u] = (1ll << (n - (int)log2(u))) - 1;
                }
                d[u] -= d[last];
                u >>= 1;
            }
            fa[last] = 1;
        }
    }
    cout << ans << "\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}