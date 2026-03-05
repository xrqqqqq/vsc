
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
array<int, 2> a[N];
int d[N];
vector<int> ne[N];
int n;
int v[N];
int dp[N][2];
int dd[N][2];
vector<array<int, 2>> f[N][2];
void dfs(int u, int fa) {
    dp[u][1] = 1;
    dd[u][1] = d[u];
    for (auto i : ne[u]) {
        if (i != fa) {
            dfs(i, u);
            f[u][1].push_back({i, 0});
            dp[u][1] += dp[i][0];
            dd[u][1] += dd[i][0];
            if (dp[i][1] > dp[i][0]) {
                f[u][0].push_back({i, 1});
                dp[u][0] += dp[i][1];
                dd[u][0] += dd[i][1];
            } else if (dp[i][1] < dp[i][0]) {
                f[u][0].push_back({i, 0});
                dp[u][0] += dp[i][0];
                dd[u][0] += dd[i][0];
            } else {
                if (dd[i][1] < dd[i][0]) {
                    f[u][0].push_back({i, 1});
                    dp[u][0] += dp[i][1];
                    dd[u][0] += dd[i][1];
                } else {
                    f[u][0].push_back({i, 0});
                    dp[u][0] += dp[i][0];
                    dd[u][0] += dd[i][0];
                }
            }
        }
    }
}
void dfss(int u, int p) {
    if (!p)
        v[u] = 1;
    else
        v[u] = ne[u].size();
    for (auto [x, y] : f[u][p]) {
        dfss(x, y);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        ne[x].push_back(y);
        ne[y].push_back(x);
        d[x]++;
        d[y]++;
    }
    dfs(1, -1);
    int now = 0;
    if (dp[1][1] > dp[1][0])
        now = 1;
    else if (dp[1][1] == dp[1][0] && dd[1][1] < dd[1][0])
        now = 1;
    int u = 1;
    dfss(u, now);
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        int s = 0;
        for (auto j : ne[i]) s += v[j];
        if (s == v[i]) cnt++;
        sum += v[i];
    }
    cout << cnt << " " << sum << endl;
    for (int i = 1; i <= n; ++i) cout << v[i] << " ";
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