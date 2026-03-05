#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int mod = 998244353;
int fix(int x) {
    return (x % mod + mod) % mod;
}
void solve() {
    cin >> n >> m;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i ) {
        char c;
        int x;
        cin>> c >> x;
        if(c == '+') {
            for(int j = m; j >= x; --j) {
                dp[j] = fix(dp[j] + dp[j-x]);
            }
        }
        else {
            for(int j = x; j <= m; ++j) {
                dp[j] = fix(dp[j] - dp[j-x]);
            }
        }
        cout<<dp[m]<<'\n';
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