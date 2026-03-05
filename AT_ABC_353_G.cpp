#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n,m,k;
int tr1[N],tr2[N];
int mx = 1e18;
int ask1(int x) {
    int res = -mx;
    for(;x <=n;x += (x&(-x))) res = max(res,tr1[x]);
    return res;
}
void sum1(int x,int c) {
    for(;x; x -= x & - x) tr1[x] = max(tr1[x],c);
}
int ask2(int x) {
    int res = -mx;
    for(;x; x -= x&-x) res = max(res,tr2[x]);
    return res;
}
void sum2(int x,int c) {
    for(;x <= n;x += x & -x) tr2[x] = max(tr2[x],c);
}
array<int,2> b[N];
void solve() {
    cin>>n>>k;
    cin>>m;
    for(int i = 1;i <= n; ++i) tr1[i] = tr2[i] = -mx;
    // tr1[1] = -k;
    sum1(1,-k);
    sum2(1,k);
    tr2[1] = k;
    vector<int> f(n+1,-1e18);
    f[1] = 0;
    int ans = 0;
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin>>x>>y;
        f[x] = max(f[x],ask1(x) + y + x * k);
        f[x] = max(f[x],ask2(x) + y - x*k);
        ans = max(ans,f[x]);
        sum1(x,f[x] - x * k);
        sum2(x,f[x] + x * k);

    }
    cout<<ans;
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while(T --) {
        solve();
    }
}