#include <bits/stdc++.h>
using namespace std;
#define int long long
#define a2 array<int, 2>
const int N = 1e6 + 10;
int n, m, k;
a2 a[N];
struct A {
    int id;
    int v, w;
};
A b[N];
int dp[N];
void solve() {
    int V;
    cin >> n >> V >> k;
    for (int i = 1; i <= n; ++i) {
        int w, v;
        cin >> v >> w;
        a[i] = {v, w};
    }
    sort(a + 1, a + n + 1);
    vector<int> v(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        auto [v, w] = a[i];
        b[i] = {i, v, w};
    }
    auto cmp = [&](const A a, const A b) { return a.w > b.w; };
    sort(b + 1, b + 1 + n, cmp);
    set<int> s;
    for (int i = 1; i <= k && i <= n; ++i) {
        sum += b[i].w;
        s.insert(b[i].id);
    }
    int ans = sum;
    int now = k + 1;

    for (int i = 1; i <= n; ++i) {
        int tem = 0;
        for (int j = V; j >= a[i][0]; --j) {
            dp[j] = max(dp[j], dp[j - a[i][0]] + a[i][1]);
            tem = max(tem, dp[j]);
        }
        v[i] = 1;

        if (s.count(i)) {
            sum -= a[i][1];
            s.erase(i);
            while (now <= n && v[b[now].id]) {
                now++;
            }
            if (now <= n) {
                s.insert(b[now].id);
                sum += b[now].w;
                now++;
            }
            ans = max(ans, sum + tem);
        }
        ans = max(ans, sum + tem);
    }
    cout << ans << "\n";
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