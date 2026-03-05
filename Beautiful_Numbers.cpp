#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 14;
const int M = N * 10;
int dp[N][M][M][M];
int n, m;
int a[N];
int len;
void calc(int x) {
    while (x) {
        a[++len] = x % 10;
        x /= 10;
    }
}
int f(int u, int x, int sum, int last, bool flag) {
    if (u == 0) return (x == sum) && (last % x == 0);
    if (sum > x) return 0;
    if (flag && dp[u][x][sum][last] != -1) return dp[u][x][sum][last];
    int mxi = flag ? 9 : a[u];
    int ans = 0;
    for (int i = 0; i <= mxi; ++i) {
        ans += f(u - 1, x, sum + i, (last * 10 + i) % x, flag || (i < mxi));
    }
    dp[u][x][sum][last] = ans;
    return ans;
}
int t = 0;
void solve() {
    t++;
    int n;
    cin >> n;
    len = 0;
    calc(n);
    for(int i = 0; i <= len; ++i) {
        for(int j = 1; j  <= len * 9; ++j) {
            for(int k = 0; k <= len*9; ++k) {
                for(int l = 0; l <= len * 9; ++l) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= len * 9; ++i) {
        ans += f(len, i, 0, 0, 0);
    }
    cout << "Case " << t << ": ";
    cout << ans << endl;
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