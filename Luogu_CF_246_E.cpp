
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int c[N];
string name[N];
unordered_map<int, int> ask[N];
int son[N], fa[N], si[N];
vector<array<int, 2>> ans;
vector<int> ne[N];
int dep[N];
set<string> cnt[N];
void dfs1(int u,int de) {
    dep[u] = de;
    si[u] = 1;
    int mx = 0, id = 0;
    for (auto i : ne[u]) {
        if (i == fa[u]) continue;
        dfs1(i, de+1);
        si[u] += si[i];
        if (si[i] > mx) {
            mx = si[i];
            id = i;
        }
    }
    if (id) son[u] = id;
}
void dfs3(int u, int p,int fad) {
    cnt[dep[u]].insert(name[u]);
    for (auto i : ne[u]) {
        if (i == fa[u] || i == p) continue;
        dfs3(i, p,fad);
    }
}
void init(int u,int fad) {
    cnt[dep[u]].erase(name[u]);
    for (auto i : ne[u]) {
        if (i == fa[u]) continue;
        init(i,fad);
    }
}
void dfs2(int u) {
    for (auto i : ne[u]) {
        if (i == fa[u] || i == son[u]) continue;
        dfs2(i);
        init(i,dep[i]);
    }
    if (son[u]) dfs2(son[u]);
    dfs3(u, son[u],dep[u]);
    for (auto [x, y] : ask[u]) {
        ask[u][x] = cnt[x+dep[u]].size();
    }
}
void solve() {
    cin>>n;
    int root = 0;
    for(int i = 1; i <= n; ++i) {
        cin>>name[i] >> fa[i];
        ne[i].push_back(fa[i]);
        ne[fa[i]].push_back(i);
    }
    cin>>m;
    for(int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        ask[x][y] = 0;
        ans.push_back({x,y});
    }
    dfs1(0,0);
    dfs2(0);
    for(auto [x,y] : ans) {
        cout<<ask[x][y]<<"\n";
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