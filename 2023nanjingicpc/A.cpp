#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 10;
int n, m, k;
int g[N][N];
#define int long long
#define a4 array<int, 4>
unordered_map<int, int> ha;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void solve() {
    cin >> n >> m;
    auto h = [&](a4 t) {
        return t[0] * n * m * m + t[1] * n * m + t[2] * m + t[3];
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            g[i][j] = 0;
        }
    }
    ha.clear();

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'O') g[i][j] = 1;
        }
    }
    int ans = 0;
    auto cu = [&](int x, int y) {
        return x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 1;
    };

    function<bool(int x, int y, int xx, int yy)> dfs = [&](int x, int y, int xx,
                                                           int yy) {
        if (ha.count((h(a4{x, y, xx, yy}))))
            return (bool)ha[h(a4{x, y, xx, yy})];
        queue<a4> q;
        vector<int> p;
        int s = h(a4{x, y, xx, yy});
        q.push({x, y, xx, yy});
        bool v = 0;
        ha[s] = 0;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            p.push_back(h(t));
           
            for (int i = 0; i < 4; ++i) {
                int x = t[0] + dx[i];
                int y = t[1] + dy[i];
                int xx = t[2] + dx[i];
                int yy = t[3] + dy[i];
                if (!cu(x, y)) {
                    if (cu(xx, yy))
                        v = 1;
                    else if (ha.count(h(a4{x, y, xx, yy})) == 0) {
                        ha[h(a4{x,y,xx,yy})] = 0;
                        q.push({x, y, xx, yy});
                    
                    }
                }
            }
        }
        
            for (auto i : p) {
                ha[i] |= v;
            }
        return v;
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 0) {
                bool v = 0;
                for (int ii = 0; ii < n; ++ii) {
                    for (int jj = 0; jj < m; ++jj) {
                        if (g[ii][jj] == 0) {
                            if (i == ii && j == jj) continue;
                            if (!dfs(i, j, ii, jj)) {
                                v = 1;
                                break;
                            }
                        }
                    }
                    if (v) break;
                }
                if (!v) ans++;
            }
        }
    }
    cout << ans << "\n";
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