#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,m,k;
int mod = 1e9 + 7;
int dp[N][4];
string p = " ABC";
void solve() {
    string s;
    cin>>s;
    n = s.size();
    s = " " + s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= 3; ++j) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j];
            }
            else {
                if(s[i] == p[j] || s[i] == '?') {
                    dp[i][j] = (dp[i-1][j-1] + dp[i][j])%mod;
                }
                dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            }
        }
        if(s[i] == '?') {
            for(int j = 0; j <= 3; ++j) {
                dp[i][j] = (2*dp[i-1][j]%mod + dp[i][j])%mod;
            }
        }
    }
    cout<<dp[n][3]%mod<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}