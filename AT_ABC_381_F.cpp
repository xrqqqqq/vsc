#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
// vector<int> ne[100];
int dp[N][21];
int ne[N][21];
int st[(1<<20)];
int a[N];
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i]--;
    }
    for(int j = 0; j <= 19; ++j) {
        dp[n+1][j] = 1e7;
    }
    a[n+1] = 1e3;
    for(int i = n; i >= 0; --i) {
        for(int j = 0; j < 20; ++j) {
            dp[i][j] = dp[i+1][j];
            if(a[i+1] == j) {
                dp[i][j] = i+1;
            }
         }
    }
    for(int i =0 ; i < (1 << 20); ++i) {
        st[i] = 1e7;
    }
    st[0] = 0;
    int ans = 0;
    for(int i = 0; i < (1<<20); ++i) {
        int cnt = 0;
        for(int j = 0; j < 20; ++j) {
            if((i >> j) & 1ll) {
                int last = i - (1<<j);
                if(st[last] <= n) {
                    int res = 1e8;
                    int fist = dp[st[last]][j];
                    if(fist <= n) {
                        res = dp[fist][j];
                        // cout<<fist<<"\n";
                        // cout<<j<<" "<<last<<" "<<res<<"\n";
                    }
                    st[i] = min(st[i],res);
                }
                cnt++;
            }
        }
        if(st[i] <= n) {
            ans = max(cnt,ans);
        }
    }
    cout<<ans*2<<"\n";
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