
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, k;
int c[N];
vector<int> ne[N];
int sum, mx;
int ans[N];
int cnt[N];
int si[N], son[N], fa[N];
void dfs1(int u, int f) {
    fa[u] = f;
    si[u] = 1;
    int mx = 0, id = 0;
    for (auto i : ne[u]) {
        if (i == f) continue;
        dfs1(i, u);
        si[u] += si[i];
        if (si[i] > mx) {
            mx = si[i];
            id = i;
        }
    }
    if (id) son[u] = id;
}
void init(int u) {
    cnt[c[u]]--;
    for (auto i : ne[u]) {
        if (i == fa[u]) continue;
        init(i);
    }
}
void dfs3(int u,int p) {
    cnt[c[u]]++;
    if (cnt[c[u]] > mx) {
        mx = cnt[c[u]];
        sum = c[u];
    } else if (cnt[c[u]] == mx) {
        sum += c[u];
    }
    for (auto i : ne[u]) {
        if (i == fa[u] || i == p) continue;
        dfs3(i,p);
    }
}
void dfs2(int u) {
    sum = 0,mx = 0;
    for (auto i : ne[u]) {
        if (i == fa[u] || i == son[u]) continue;
        dfs2(i);
        init(i);
        sum = 0, mx = 0;
    }
    if (son[u]) dfs2(son[u]);
    dfs3(u,son[u]);
    ans[u] = sum;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
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