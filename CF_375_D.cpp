
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, k;
int c[N];
int tr[N];
void add(int i, int c) {
    for (; i; i -= i & -i) {
        tr[i] += c;
    }
}
int sum(int i) {
    int res = 0;
    for (; i <= n; i += i & -i) {
        res += tr[i];
    }
    return res;
}
int cnt[N];
unordered_map<int, int> ask[N];
int son[N], fa[N], si[N];
vector<array<int, 2>> ans;
vector<int> ne[N];
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
void dfs3(int u, int p) {
    int last = cnt[c[u]];
    cnt[c[u]]++;
    int now = cnt[c[u]];
    // cout << last << " " << now << "\n";
    if(last) add(last,-1);
    if(now) add(now,1);
    for (auto i : ne[u]) {
        if (i == fa[u] || i == p) continue;
        dfs3(i, p);
    }
}
void init(int u) {
    int last = cnt[c[u]];
    cnt[c[u]]--;
    int now = cnt[c[u]];
    if (last) add(last, -1);
    if (now) add(now, 1);
    for (auto i : ne[u]) {
        if (i == fa[u]) continue;
        init(i);
    }
}
void dfs2(int u) {
    for (auto i : ne[u]) {
        if (i == fa[u] || i == son[u]) continue;
        dfs2(i);
        init(i);
    }
    if (son[u]) dfs2(son[u]);
    dfs3(u, son[u]);
    for (auto [x, y] : ask[u]) {
        if (x > n)
            ask[u][x] = 0;
        else
            ask[u][x] = sum(x);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        ask[x][y] = 0;
        ans.push_back({x, y});
    }
    dfs1(1, 0);
    dfs2(1);
    for (auto [x, y] : ans) {
        cout << ask[x][y] << "\n";
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