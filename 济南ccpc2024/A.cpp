#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
void solve() {
    map<string, array<int, 2>> t;
    map<string, int> tt;
    cin >> n >> m >> k;
    for (int j = 1; j <= n; ++j) {
        string s;
        cin >> s;
        int ii = 0;
        string p = "";
        for (int i = 1; i <= m * k; ++i) {
            p += s[i - 1];
            if (i % k == 0) {
                tt[p]++;
                t[p] = {j, ii+1};
                ii++;
                p = "";
            }
        }
    }
    for (auto [x, y] : t) {
        if (tt[x] == 1) {
            cout << y[0] << " " << y[1] << "\n";
            return;
        }
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