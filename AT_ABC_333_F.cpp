#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e3 + 10;
const int mod = 998244353;
int f[N][N];
int n;
int ksm(int a,int b) {
    int res = 1;
    while(b) {
        if(b&1ll) res = (res * a) % mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}
int inv2;
int fix(const int x) {
    return (x%mod + mod)%mod;
}
array<int,2> ff(int i,int j) {
    if(i == 1) {
        return array<int,2>{1,0};
    }
    auto p = ff(i-1,j);
    return array<int,2>{inv2*p[0]%mod,fix(inv2*p[1]%mod + inv2*f[i-1][j-1]%mod)};
}

void solve() {
    f[1][1] = 1;
    cin>>n;
    inv2 = ksm(2,mod-2);
    for(int j = 2; j <= n; ++j) {
        for(int i = 1 ; i <= j; ++i) {
            if(i == 1) {
                auto p = ff(j,j);
                f[i][j] = p[1]*ksm(fix(2-p[0]),mod-2)%mod;
            }
            else {
                f[i][j] = fix(inv2*f[i-1][j]%mod + inv2*f[i-1][j-1]%mod); 
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout<<f[i][n]<<" ";
    }
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}