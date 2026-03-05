#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
const int N = 3e5 + 10;
vector<int> ne[N];
vector<array<int, 2>> ad;
bool st;
int dfs(int u, int fa) {
    vector<int> ned;
    int sha = 0;
    for (auto i : ne[u]) {
        if (i == fa) continue;
        int p = dfs(i, u);
        ned.push_back(p);
    }
    if (ned.size() == 0) return {u};
    if (ned.size() % 2 == 0) {
        for (int i = 0; i < ned.size(); i += 2) {
            ad.push_back({ned[i], ned[i + 1]});
        }
        return {u};
    } else {
        for (int i = 0; i < ned.size() - 1; i += 2) {
            ad.push_back({ned[i], ned[i + 1]});
        }
        return ned[ned.size() - 1];
    }
}
void solve() {
    ad.clear();
    cin >> n;
    vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        ne[i].clear();
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        d[x]++;
        d[y]++;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    st = 0;
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] % 2 == 0) st = 1, root = i;
    }
    if (st == 0) {
        cout << -1 << "\n";
        return;    
    }
    dfs(root, -1);
    cout << ad.size() << "\n";
    for (auto i : ad) {
        cout << i[0] << " " << i[1] << "\n";
    } 
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