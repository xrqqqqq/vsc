#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
int mod = 1e9;
int n, m;
vector<array<int, 2>> ne[N];
void solve() {
    int mx = 0;
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int x, y;
        int c;
        cin >> x >> y >> c;
        ne[x].push_back({y, c});
        ne[y].push_back({x, c});
        mx = max(mx, c);
    }
    auto check = [&](int tem) -> int {
        vector<int> f(n + 1, 1e18);
        function<void(int, int)> dfs = [&](int u, int fa) {
            int sum = 0;
            for (auto [x, c] : ne[u]) {
                if (x == fa) continue;
                int cost = c;
                if (cost > tem) {
                    cost = 1e13;
                }
                dfs(x, u);
                sum += min(f[x], cost);
            }
            if (sum == 0) sum = 1e13;

            f[u] = min(f[u], sum);
        };
        dfs(1, -1);
        return f[1] <= m;
    };
    int l = 1, r = mx;
    while (l < r) {
        int m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    if (check(l) == 0) {
        cout << -1 << endl;
        return;
    }
    cout << l << endl;
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