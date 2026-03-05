#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 3e5 + 10;
int n, m;
int a[N];
int dp[(1ll<<14)];
void test() {
    cin>>n>>m;
    int mx = (1ll<<(13)) - 1;
    for(int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        a[x]++;
    }
    // for(int i = )
    for(int i = 0; i <= mx; ++i) {
        dp[i] = 1e18;
    }
    dp[0] = 0;
    for(int i = 0; i <= mx; ++i) {
        for(int j = i;; j = i&(j-1)) {
            int now = i^j;
            int sum = 0;
            for(int k = 0; k <= 12; ++k) {
                if(now >> k&1ll) {
                    sum += a[k + 1];
                }
            }
            if(sum <= m) {
                dp[i] = min(dp[i],dp[j] + 1);
            }
            if(j == 0) break;
        }
    }
    cout<<dp[mx]<<"\n";
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