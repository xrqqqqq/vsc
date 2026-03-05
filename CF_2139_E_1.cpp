#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
vector<int> ne[N];
int d[N];
int mi = 1e18;
void dfs(int u, int fa, int dep) {
    for (auto v : ne[u]) {
        if (v != fa) {
            dfs(v, u, dep + 1);
        }
    }
    if (ne[u].size() == 1&&u!=1) {
        mi = min(mi, dep);
    }
    d[dep]++;
    
    
}
void solve() {
    cin >> n >> k;
    mi = n;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        ne[x].push_back(i);
        ne[i].push_back(x);
        d[i] = 0;
    }
    d[1] = 0;
    dfs(1, -1, 1);
    int t1 = k, t2 = n - k;
    vector<vector<int>> dp(n + 1, vector<int>(t1 + 1));
    dp[0][0] = 1;
    int sum = 0;
    int len = 0;
    for (int i = 1; i <= n && i <= mi; ++i) {
        sum += d[i];
        for (int j = 0; j <= t1; ++j) {
            if (j <= sum && sum - j <= t2)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j - d[i] >= 0 && sum - j <= t2)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - d[i]]);
            if (dp[i][j]) len = max(len, i);
        }
    }
    cout << len << "\n";
    for (int i = 1; i <= n; ++i) ne[i].clear();
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