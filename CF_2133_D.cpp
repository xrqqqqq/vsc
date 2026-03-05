#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    vector<int> dp(n + 1,1e18);
    dp[0] = 0;
    dp[1] = a[1];
    for(int i = 2; i <= n; ++i) {
        dp[i] = min(dp[i-2]+ a[i-1] + max(a[i] - (i- 1),0ll),dp[i-1] + a[i] - 1);
        // cout<<dp[i]<<"\n";
    }
    cout<<dp[n]<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin>>T;
    while(T--) {
        solve();
    }
}