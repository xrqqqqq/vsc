#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
const int N = 305;
int a[N];
int c[N];
void solve() {
    cin >> n;
    int t = 0;
    vector<map<int, int>> dp(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i], t = __gcd(t, a[i]);
    for(int  i= 1; i <= n; ++i) {
        cin>>c[i];
    }
    if (t != 1) {
        cout << -1 << "\n";
        return;
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (auto& [x, v] : dp[i]) {
            int t = __gcd(x, a[i + 1]);
            if (dp[i + 1].count(t) == 0) {
                dp[i + 1][t] = v + c[i+1];
            }
            else {
                dp[i+1][t] = min(dp[i+1][t],v+c[i+1]);
            }
            if(dp[i+1].count(x)== 0) {
                dp[i+1][x] = v;
            }
            else {
                dp[i+1][x] = min(dp[i+1][x],v);
            }
        }
    }
    cout<<dp[n][1]<<"\n";
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
