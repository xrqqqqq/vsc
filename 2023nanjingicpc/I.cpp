#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
#define a2 array<int, 2>
void solve() {
    cin >> n >> m;
    vector<a2> tem;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        tem.push_back({x, y});
    }
    sort(tem.begin(), tem.end());
    int last = 0;
    int x = 0;
    for (auto [t, y] : tem) {
        int te = t - last;
        last = t;
        if (y == x + te) {
        } else if (y < te) {
        } else {
            cout << "No\n";
            return;
        }
        x = y;
    }
    cout << "Yes\n";
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