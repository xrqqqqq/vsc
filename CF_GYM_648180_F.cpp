#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e5 + 10;
int n, m;
int a[N];
int ne[N];
int mx[N];
int dp[N];
void test() {
    cin >> n;
    int last = 0;
    for (int i = 0; i <= n; ++i) {
        mx[i] = -inf;
    }
    a[0] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (last == i - 1) {
            mx[i] = a[i] + i - last;
        } else {
            mx[i] = max(mx[i - 1], a[i] + i - last);
        }
        ne[i] = last;
        if (mx[i] < 0) {
            if (a[last] >= 0) {
                dp[i] = dp[last];
            } else {
                dp[i] = mx[i];
            }
        } else {
            dp[i] = dp[last] + mx[i];
        }
        if (a[i] >= 0) last = i;
    }
    cout << dp[n] << "\n";
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