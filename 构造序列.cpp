#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int mod = 1e9 + 7;
int f[N];
int nf[N];
int ksm(int a,int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>=1;
    }
    return res;
}
int C(int a,int b) {
    if(a < b) return 0;
    return f[a]*nf[b]%mod*nf[a-b]%mod;
}
int A(int a,int b) {
    return f[a]*nf[a-b]%mod;
}
void solve() {
    cin>>n>>m;
    int mx = 2*n;
    f[1] = f[0] = nf[1] = nf[0] = 1;
    for(int i = 2; i <= mx; ++i) 
    f[i] = (f[i-1]*i) % mod;
    nf[mx] = ksm(f[mx],mod-2);
    for(int i = mx - 1; i >= 2; --i) {
        nf[i] = (nf[i+1]*(i+1))%mod;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int len = n - i*(i+1)/2;
        if(len < 0) break;
        int res = (m % mod) * ksm((m - 1) % mod, i - 1) % mod;

        ans = (ans + res*C(i+len,len)%mod)%mod;
    }
    cout<<ans;
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