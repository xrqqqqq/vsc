
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 10;
int dp[505][N];
int n,m,k;
int K;
int V;
array<int,2> ne[505][505];
void test() {
    cin>>n>>V>>K;
    for(int i = 1; i <= n; ++i) {
        int v,w,c;
        cin>>v>>w>>c;
        ne[++ne[c][0][0]][c] = {v,w};
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0;j <= V; ++j) {
            dp[i][j] = dp[i-1][j];
        }
        for(int kk = 1; kk <= ne[i][0][0]; ++kk) {
            auto [v,w] = ne[kk][i];
            for(int j = V; j >= v; --j) {
                dp[i][j] = max({dp[i][j],dp[i-1][j-v] + K + w,dp[i][j-v] + w});
            }
        }
    }
    // for(int j = 0; j <= V; ++j) {
    //     cout<<dp[n][j]<<"\n";
    // }
    cout<<dp[n][V]<<"\n";
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