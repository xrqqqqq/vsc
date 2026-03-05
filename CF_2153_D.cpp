#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int f2(int a,int b) {
    return abs(a - b);
}
int f3(int a,int b,int c) {
    return max({a,b,c}) - min({a,b,c});
}
void solve() {
    cin>>n;
    for(int i = 1;i <= n; ++i) {
        cin>>a[i];
    }
    int ans = 1e18;
    for(int l = 0;l <= 2; ++l) {
        vector<int> dp(n+1,1e18);
        dp[0] = 0;
        for(int i = 0; i <= n;++i) {
            if(i + 2<= n) {
                dp[i+2] = min(dp[i+2],dp[i]+f2(a[i+1],a[i+2]));
            }
            if(i + 3 <= n) {
                dp[i+3] = min(dp[i+3],dp[i]+f3(a[i+1],a[i+2],a[i+3]));
            }
        }
        ans = min(ans,dp[n]);
        int t = a[1];
        // cout<<dp[n]<<"\n";
        for(int i = 1; i < n; ++i) {
            a[i] = a[i+1];
        }
        a[n] = t;
        // for(int i = 1; i <= n; ++i) {
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
    }
    cout<<ans<<"\n";
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