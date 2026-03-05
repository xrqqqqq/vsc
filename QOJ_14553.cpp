#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
int B;
map<int, vector<int>> ha;
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ha[a[i]].push_back(i);
    }
    B = sqrt(n);
    map<int, map<int, int>> res;
    vector<int> tem;
    for (auto [x, y] : ha) {
        if (y.size() >= B) {
            tem.push_back(x);
        }
    }
    for (auto t : tem) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (ha[a[i]].size() >= B) {
                res[t][a[i]] += sum;
            }
            if (a[i] == t) {
                sum++;
            }
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        auto &xx = ha[x];
        auto &yy = ha[y];
        if (xx.size() >= B && yy.size() >= B) {
            cout << res[x][y] << "\n";
        } else if (xx.size() < B) {
            int ans = 0;
            for (auto i : xx) {
                ans += yy.end() - upper_bound(yy.begin(), yy.end(), i);
            }
            cout << ans << "\n";
        } else {
            int ans = 0;
            for (auto i : yy) {
                auto it = lower_bound(xx.begin(), xx.end(), i);
                it--;
                ans += it - xx.begin() + 1;
            }
            cout << ans << "\n";
        }
    }
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