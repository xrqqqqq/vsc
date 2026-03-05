#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int p[N];
int find(int x) {
    if (p[x] != x) return p[x] = find(p[x]);
    return x;
}
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1ll) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
void solve() {
    cin >> n >> m;
    priority_queue<array<int, 3>> q;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        cin >> a[i];
    }
    auto f = [&](int x, int y) {
        return (ksm(x, y) + ksm(y, x)) % m;
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            q.push({f(a[i], a[j]), i, j});
        }
    }
    int cnt = 0;
    while (q.size()) {
        auto [x, y, z] = q.top();
        q.pop();
        y = find(y), z = find(z);
        if (y != z) {
            ans += x;
            cnt++;
            if (cnt == n - 1) break;
            p[y] = z;
        }
    }
    cout << ans;
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