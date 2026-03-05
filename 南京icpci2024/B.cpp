#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9;
void solve() {
    // int n;
    string s;
    cin >> s;
    int n = s.size();
    s = '.' + s;
    vector<vector<int>> f(n+5,vector<int>(2,inf));
    f[0][0] = f[0][1] = 0;
    for (int i = 1; i <= n; i++) {

        // if (f[i-1][0] == 0 )
        if (s[i] == '1') {
            f[i][1] = f[i-1][0] + 1;
            if (f[i - 1][1] < 1e9 && f[i - 1][1]) {
                f[i][0] = f[i - 1][1] - 1;
            }

        } else if (s[i] == '0') {
            f[i][0] = f[i-1][1] + 1;
            if (f[i - 1][0] < 1e9 && f[i - 1][0]) {
                f[i][1] = f[i - 1][0] - 1;
            }

        } else {
            f[i][1] = f[i - 1][0] + 1;
            if (f[i - 1][1] < 1e9 && f[i - 1][1]) {
                f[i][0] = f[i - 1][1] - 1;
            }
            f[i][0] = min(f[i][0],f[i - 1][1] + 1);
            if (f[i - 1][0] < 1e9 && f[i - 1][0]) {
                f[i][1] = min(f[i][1],f[i - 1][0] - 1);
            }
        }
        cout<<f[i][0]<<' '<<f[i][1]<<'\n';
    }
    cout << min(f[n][0],f[n][1]) << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}