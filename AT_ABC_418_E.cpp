#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;

struct f {
    size_t operator()(const pair<int,int> &t) const{
        size_t h1 = hash<int> ()(t.first);
        size_t h2 = hash<int> ()(t.second);
        return h1 ^ (h2 << 1);
    }
};
unordered_map<pair<int, int>, int, f> ha1;
unordered_map<pair<int, int>, int, f> ha2;

array<int, 2> aa[N];
int n;
void solve() {
    ha1.clear();
    ha2.clear();

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> aa[i][0] >> aa[i][1];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            auto [x1, y1] = aa[i];
            auto [x2, y2] = aa[j];

            int dx = x1 - x2;
            int dy = y1 - y2;
            int get = __gcd(abs(dx), abs(dy));
            dx /= get;
            dy /= get;
            if (dx < 0 || (dx == 0 && dy < 0)) dx = -dx, dy = -dy;

            ha1[{dx, dy}]++;

            int ddx = x1 + x2;
            int ddy = y1 + y2;
            ha2[{ddx, ddy}]++;
        }
    }

    int ans1 = 0, ans2 = 0;
    for (auto [x, y] : ha1) {
        if (y >= 2) ans1 += y * (y - 1) / 2;
    }
    for (auto [x, y] : ha2) {
        if (y >= 2) ans2 += y * (y - 1) / 2;
    }

    cout << ans1 - ans2 << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while (T--) solve();
}
