#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, k;
map<pair<int,int>, int> dp;
int mod = 998244353;
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int f[N];
int nf[N];
int fix(int x) { return (x % mod + mod) % mod; }
int C(int a, int b) {
    if (b > a) return 0;
    return f[a] * nf[b] % mod * nf[a - b] % mod;
}
int dfs(int n, int m) {
    if(dp.find({n,m})!=dp.end()){
        return dp[{n,m}];
    }
    int res=C(m-1,n-1);
    for(int i=2;m/i>=n-1&&n>1;i++){
        res=(res+dfs(n-1,m/i))%mod;
    }
    return dp[{n,m}]=res;
    // return res;
}
void solve() {
    cin >> m >> n;
    f[0] = nf[0] = f[1] = nf[1] = 1;
    for (int i = 2; i <= m; ++i) f[i] = f[i - 1] * i % mod;
    nf[m] = ksm(f[m], mod - 2);
    for (int i = m - 1; i >= 2; --i) nf[i] = (nf[i + 1] * (i + 1)) % mod;
    // cout<<C(4,2);
    int ans=0;
    for(int i=1;m/i>=n;i++){
        ans=(ans+dfs(n,m/i))%mod;
    }
    ans=(n*C(m,n)%mod-ans+mod)%mod;
    cout<<ans<<'\n';
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