#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
const int N = 3e4 + 10;
int a[N];
int c[N];
void solve() {
    int d;
    cin >> n >> d;
    vector<vector<int>> dp(N, vector<int>(6e2 + 100, -1e18));
    unordered_map<int, int> t;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        t[x]++;
    }
    int dd = 3e2;
    dp[d][dd] = t[d];
    int ans = 0;
    for (int i = d; i <= 30000; ++i) {
        for (int j = -dd + 1; j < dd; ++j) {
            ans = max(ans, dp[i][j + dd]);
            int jj = j + 1 + d;
            if (i + jj <= 30000 && jj >= 1) {
                dp[i + jj][jj + dd - d] = max(dp[i][j + dd] + t[i + jj],
                                                  dp[i + jj][jj + dd - d]);
            }
            jj--;
            if (i + jj <= 30000 && jj >= 1) {
                dp[i + jj][jj + dd - d] =
                    max(dp[i][j + dd] + t[i + jj], dp[i + jj][jj + dd - d]);
            }
            jj--;

            if (i + jj <= 30000 && jj >= 1) {
                dp[i + jj][jj + dd - d] =
                    max(dp[i][j + dd] + t[i + jj], dp[i + jj][jj + dd - d]);
            }
        }
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
