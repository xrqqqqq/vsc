#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 50 + 10;
int n, m, k;
int a[N];
int g[N][N];
int v[N][N];
int dp[N][N][10005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void solve() {
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
            v[i][j] = -1;
        }
    }
    
   
    int mx = min(10000ll,k);
    for(int kk = 0;kk <= mx; ++kk) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                dp[i][j][kk] = -1e18;
            }
        }
    }
    dp[x][y][0] = 0;
    int ans = 0;
    for(int kk = 1; kk <= mx; ++kk)
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j][kk] = max(dp[i][j][kk],g[i][j] + dp[i][j][kk-1]);
            for(int t = 0; t < 4; ++t) {
                int xx = i + dx[t],yy = j + dy[t];
                if(xx >= 1&&xx <= n &&yy >= 1&&yy <= m) {
                    // cout << dp[xx][yy][kk - 1] << "\n";
                    // cout<<xx<<" "<<yy<<'\n';
                    dp[i][j][kk] = max(dp[i][j][kk],dp[xx][yy][kk-1] + g[i][j]);
                }
            }
            // cout<<dp[i][j][kk]<<" "<<i<<" "<<j<<" "<<kk<<"\n";
            ans = max(ans,dp[i][j][kk] + max(0ll,k-kk)*g[i][j]);
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