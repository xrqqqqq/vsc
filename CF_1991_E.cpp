#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
int v[N];
bool ok = 0;
void dfs(int u, int s, int fa) {
    v[u] = s;
    for (auto i : ne[u]) {
        if (i == fa) continue;
        if (v[i] == 0) {
            dfs(i, s + 1, u);
        } else {
            if (abs(s - v[i]) % 2 == 0) {
                ok = 1;
            }
        }
    }
}
void dfss(int u, int s) {
    v[u] = s;
    int ss = s;
    if (ss == 2)
        ss = 1;
    else
        ss = 2;
    for (auto i : ne[u]) {
        if (v[i] == 0) {
            dfss(i, ss);
        }
    }
}
void solve() {
    cin >> n >> m;
    ok = 0;
    for (int i = 1; i <= n; ++i) ne[i].clear();
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) v[i] = 0;
    dfs(1, 1, -1);

    if (ok) {
        cout << "Alice" << endl;
        for (int i = 1; i <= n; ++i) {
            cout << 1 << " " << 2 << endl;
            int x, c;
            cin >> x >> c;
        }
    } else {
        for (int i = 1; i <= n; ++i) v[i] = 0;
        dfss(1, 1);
        vector<int> t1, t2;
        for (int i = 1; i <= n; ++i) {
            if (v[i] == 1)
                t1.push_back(i);
            else
                t2.push_back(i);
        }

        cout << "Bob" << endl;
        for (int i = 1; i <= n; ++i) {
            int a, b;
            cin >> a >> b;
            vector<int> ha(3 + 1);
            if (a > b) swap(a, b);
            ha[a]++;
            ha[b]++;
            int t[3];
            if (a == 1 && b == 2) {
                t[1] = 1;
                t[2] = 2;
            } else if (a == 1 && b == 3) {
                t[1] = 1;
                t[2] = 3;
            } else {
                t[1] = 3;
                t[2] = 2;
            }
            if (ha[1] || ha[2]) {
                if (t1.size() && ha[1]) {
                    cout << t1.back() << " " << 1 << endl;
                    t1.pop_back();
                    continue;
                } else if (t2.size() && ha[2]) {
                    cout << t2.back() << " " << 2 << endl;
                    t2.pop_back();
                    continue;
                }
            }
            if (t1.size()) {
                cout << t1.back() << " " << t[1] << endl;

                t1.pop_back();
            } else {
                cout << t2.back() << " " << t[2] << endl;

                t2.pop_back();
            }
        }
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