
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int f[N];
int nf[N];
int b[N];
int a[N],w[N];
int si[N];
int mod = 1e9 + 7;
int fix(const int x) {
    return (x % mod + mod )% mod;
}
int ksm(int a,int b) {
    int res = 1;
    while(b) {
        if(b & 1) res=  (res * a)%mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void init(int n) {
    f[1] = nf[1] = 1;
    f[0] = nf[0] = 1;
    for(int i = 2; i  <= n; ++i) {
        f[i] = f[i-1]*i%mod;
    }
    nf[n] = ksm(f[n],mod-2); 
    for(int i = n - 1; i >= 2; --i) {
        nf[i] = nf[i+1]*(i+1)%mod;
    }
}
void dfs(int u) {
    if(si[u] != -1) return ;
    if(a[u] < a[b[u]]) {
        si[u] = 1;
        return ;
    }
    else if(a[u] >= a[b[u]] + w[b[u]]) {
        si[u] = 0;
        return ;
    }
    si[u] = 0;
    dfs(b[u]);
    if(si[b[u]] != 0) {
        si[u] = si[b[u]] + 1;
    }
}  
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        si[i] = -1;
        cin>>a[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin>>b[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin>>w[i];
    }
    for(int i = 1;i <= n; ++i) {
        if(si[i] == -1) {
            dfs(i);
        }
        if(si[i]) {
            cout<<fix(a[i] + nf[si[i]]*w[i]%mod)<<" ";
        }
        else {
            cout<<a[i]<<" ";
        }
    }
    cout<<"\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init(5e5);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}