
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n;
    multiset<int> s;
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    function<int(int)> f = [&](int x) { return (x + 1) / 2; };
    for (int i = 1; i < n; ++i) {
        s.erase(s.find(a[i]));
        s.erase(s.find(a[i + 1]));
        if (s.size()) ans = min(ans, f(min(a[i], a[i + 1])) + f(*s.begin()));
        s.insert(a[i]);
        s.insert(a[i + 1]);
    }
    for (int i = 1; i < n; ++i) {
        int x = a[i], y = a[i + 1];
        if (y > x) swap(x, y);
        if (x >= 2 * y) {
            ans = min(ans, f(x));
        } else {
            int ned = x - y;
            if (ned >= y) {
                ans = min(ans, f(x));
            } else if (x - 2 * ned <= 0) {
                ans = min(ans, f(x));
            } else {
                int tem = ned;
                x -= tem * 2, y -= tem;
                int t = x / 3;
                tem += t * 2;
                if (x % 3 == 1)
                    tem += 1;
                else if (x % 3 == 2)
                    tem += 2;
                ans = min(ans, tem);
            }
        }
    }
    for (int i = 1; i < n-1; ++i) {
        int x = a[i], y = a[i + 2];
        if (y > x) swap(x, y);
        int tem = f(x) + f(y);
        if(x % 2 == 1 && y % 2 == 1) {
            tem --;
        }
        ans = min(ans,tem);
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