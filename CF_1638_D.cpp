#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e3 + 10;
int v[N][N];
vector<array<int, 3>> ans;
int n, m;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
bool z(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
void er(int x, int y) {
    v[x][y] = v[x + 1][y] = v[x + 1][y + 1] = v[x][y + 1] = 0;
}
int check(int x, int y) {
    if (!z(x, y) || !z(x, y + 1) || !z(x + 1, y) || !z(x + 1, y + 1)) return 0;
    int se = 0;
    if (se != v[x][y] && v[x][y]&&se) return 0;
    if (v[x][y]) {
        se = v[x][y];
    }
    if (se != v[x + 1][y] && v[x + 1][y]&&se) return 0;
    if (v[x + 1][y]) se = v[x + 1][y];
    if (se != v[x][y + 1] && v[x][y + 1]&&se) return 0;
    if (v[x][y + 1]) se = v[x][y + 1];
    if (se != v[x + 1][y + 1] && v[x + 1][y + 1]&&se) return 0;
    if(v[x+1][y+1]) {
        se = v[x+1][y+1];
    }
  
    return se;
}
void test() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(check(i,j)) {
                queue<array<int, 2>> q;
                q.push({i, j});
                while(q.size()) {
                    auto [x,y] = q.front();
                    q.pop();
                    if(!check(x,y)) continue;
                    ans.push_back({x, y, check(x,y)});
                    er(x, y);
                    for(int i = 0; i < 8; ++i) {
                        int a = x + dx[i],b = y + dy[i];
                        if(check(a,b)) {
                            q.push({a,b});
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (v[i][j]) {
                cout << -1 << "\n";
                return;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto [x, y, c] : ans) {
        cout << x << " " << y << " " << c << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        test();
    }
    return 0;
}