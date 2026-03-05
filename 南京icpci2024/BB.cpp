#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N = 5e5 + 10;
array<int, 2> dp[N][2];
int mx = 1e10;
array<int, 2> f(array<int, 2> x, array<int, 2> y) {
    if (x[1] < 0) return y;
    if (y[1] == -1) {
        if(x[0] < 0) {
            if(x[0]%2 == 0) x[0] = 0;
            else x[0] = 1;
        }
        return x;
    } else {
        int ll = min(x[0], y[0]);
        if (ll < 0) {
            if (ll % 2 == 0)
                ll = 0;
            else
                ll = 1;
        }
        int rr = max(x[1], y[1]);
        return {ll, rr};
    }
}
void solve() {
    // cin>>n;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i][1] = {mx, -1};
    }
    dp[0][0] = dp[0][1] = {0, 0};
    for (int i = 0; i < n; ++i) {
        if (dp[i][1][0] == 0) {
            dp[i][0] = f({0, 0}, dp[i][0]);
        }
        if (dp[i][0][0] == 0) {
            dp[i][1] = f({0, 0}, dp[i][1]);
        }
        if (s[i + 1] == '0') {
            if (dp[i][1][1] != -1)
                dp[i + 1][0] =
                    f({dp[i][1][0] + 1, dp[i][1][1] + 1}, dp[i + 1][0]);
            if (dp[i][0][1] != -1)
                dp[i + 1][1] =
                    f({dp[i][0][0] - 1, dp[i][0][1] - 1}, dp[i + 1][1]);
        } else if (s[i + 1] == '1') {
            if (dp[i][1][1] != -1)
                dp[i + 1][0] =
                    f({dp[i][1][0] - 1, dp[i][1][1] - 1}, dp[i + 1][0]);
            if (dp[i][0][1] != -1)
                dp[i + 1][1] =
                    f({dp[i][0][0] + 1, dp[i][0][1] + 1}, dp[i + 1][1]);
        } else if (s[i + 1] == '2') {
            if (i + 2 <= n) {
                if (dp[i][0][1] != -1) dp[i + 2][0] = f(dp[i][0], dp[i + 2][0]);
                if (dp[i][1][1] != -1) dp[i + 2][1] = f(dp[i][1], dp[i + 2][1]);
            }
            // if(i == 6)
            // cout<<"?\n";
            if (dp[i][1][1] != -1)
                dp[i + 1][0] =
                    f({dp[i][1][0] - 1, dp[i][1][1] + 1}, dp[i + 1][0]);
            if (dp[i][0][1] != -1)
                dp[i + 1][1] =
                    f({dp[i][0][0] - 1, dp[i][0][1] + 1}, dp[i + 1][1]);
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i][1][0] << " " << dp[i][1][1] << " 1\n";
    //     cout << dp[i][0][0] << " " << dp[i][0][1] << " 0\n";
    //     cout << "\n";
    // }
    int ans = 1e18;
    if (dp[n][1][0] >= 0) ans = min(ans, dp[n][1][0]);
    if (dp[n][0][0] >= 0) ans = min(ans, dp[n][0][0]);
    cout << ans << "\n";
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