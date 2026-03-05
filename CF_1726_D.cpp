
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int p[N];
int find(int x) {
    if (x != p[x]) return p[x] = find(p[x]);
    return x;
}
// vector<array<int,2>> ne[N];
int ans[N];
array<int, 3> te[N];
bool v[N];
int d[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        d[i] = 0;
    }
    int id = 0;
    int ii = 0;
    set<int> s;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        te[i] = {x, y, i};
        int a = find(x), b = find(y);
        if (a != b) {
            ii = i;
            ans[i] = 0;
            p[a] = b;
        } else {
            d[x]++;
            d[y]++;
            ans[i] = 1;
        }
    }
    if(m == n- 1) {
        for (int i = 1; i <= m; ++i) cout << ans[i];
        cout << "\n";
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    int to0 = -1;
    for (int i = 1; i <= m; ++i) {
        if(i == ii) continue;
        if(ans[i] == 0) {
        auto [x, y, id] = te[i];
        x = find(x), y = find(y);
        if (x != y) {
            p[x] = y;
        }
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (ans[i] == 1) {
            auto [x, y, id] = te[i];
            x = find(x), y = find(y);
            if (x != y) {
                to0 = i;
                break;
                p[x] = y;
            }
        }
    }

    bool v = 1;
    for (int i = 1; i <= n; ++i) {
        if (d[i] && d[i] != 2) {
            v = 0;
            break;
        }
    }
    if (to0 != -1 && v) {
        swap(ans[ii], ans[to0]);
    }
    for (int i = 1; i <= m; ++i) cout << ans[i];
    cout << "\n";
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