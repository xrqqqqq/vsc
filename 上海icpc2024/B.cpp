#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N = 3e5 + 10;
vector<vector<int>> G(N);
vector<pair<int, int>> ans;
int a[N];
bool vis[N];
int p = 2;
int dep = 0;
void dfs(int cur, int fa) {
    if (p >= n + 1) return;
    int cnt = 0;
    if (vis[cur]) return;
    vis[cur] = 1;
    vector<int> tmp;
    for (auto i : G[cur]) {
        if (i == fa || vis[i]) continue;
        tmp.push_back(i);
    }
    sort(tmp.begin(),tmp.end());
    while (tmp.size()) {
        if (find(tmp.begin(), tmp.end(), a[p]) != tmp.end()) {
            tmp.erase(find(tmp.begin(), tmp.end(), a[p]));
            p++;
            dfs(a[p - 1], cur);
        } else {
            ans.push_back({cur, a[p]});
            p++;
            dfs(a[p - 1], cur);
        }
        if (p >= n + 1) break;
    }

    // while (dep == 1) {
    //     ans.push_back({cur, a[p]});
    //     p++;
    //     dfs(a[p - 1], cur);
    //     if (p >= n + 1) break;
    // }

    // dep--;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    dfs(a[1], 0);

    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i.first << " " << i.second << '\n';
    }
    return 0;
}