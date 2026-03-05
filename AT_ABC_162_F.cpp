#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
const int mod = 998244353;
int n, m, k;
int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    vector<int> dp(n+1);
    int tem = a[1];
    for(int i = 2; i <= n; ++i) {
        if(i&1) {
            tem += a[i];
            dp[i] = max(dp[i-1],dp[i-2] + a[i]);
        }
        else {
            dp[i] = max(dp[i-2] + a[i],tem);
        }
    }
    cout<<dp[n]<<"\n";
}