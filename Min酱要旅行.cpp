#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2400;
int mod = 1e9;
int n,m;
int f[N];
int g[N];
int v[N];
void solve() {
    cin>>n>>m;
    f[0] = 1;
    for(int i = 1; i <= n; ++i) {
        cin>>v[i];
        for(int j = m; j >= v[i]; -- j) {
            f[j] = (f[j] + f[j-v[i]])%mod;
        }
    }
    for(int i = 1; i <= n; ++i) {
        vector<int> g(m+1);
        g[0] = 1;
        for(int j = 1; j <= m; ++j) {
            int last = j - v[i];
            if(last < 0) last = 0;
            else last = g[last];
            g[j] = (f[j] - last+ mod) %mod;
            cout<<g[j]%10;
        }
        cout<<"\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while(T--) {
        solve();
    }
}