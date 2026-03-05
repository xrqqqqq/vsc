
#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 10;
int n, m, k;
vector<int> ne[N];
int d[N];
int inf = 1e9;
vector<int> g[N];
void solve() {
    cin >> n >> m;
    vector<int> d(n + m + 10, inf);
    for (int i = 1; i <= n; ++i) {
        ne[i].clear();
    }
    for (int i = 1; i <= n + m; ++i) {
        g[i].clear();
    }
    int idx = n + 1;
    map<int, int> id;
    queue<int> q;
    for (int i = 1; i <= m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        ne[x].push_back(c);
        ne[y].push_back(c);
        if (id.count(c) == 0) id[c] = idx++;
    }
    for (int i = 1; i <= n; ++i) {
        for (auto c : ne[i]) {
            g[i].push_back(id[c]);
            g[id[c]].push_back(i);
        }
    }
    int s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << "\n";
        return;
    }
    d[s] = 0;
    q.push(s);
    while (q.size()) {
        auto u = q.front();
        q.pop();
        if (u == t) {
            cout << d[u] / 2 << "\n";
        }
        for (auto i : g[u]) {
            if (d[i] == inf) {
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }
    // cout << d[t] << "\n";
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