#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int e[N*2],ne[N*2],h[N],idx;
int a[N];
int dp[N],siz[N],sum[N];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int fa){
    siz[u]=1;
    sum[u]=a[u];
    int mn=1e18;
    for(int i=h[u];~i;i=ne[i]){
        int v=e[i];
        if(v==fa) continue;
        dfs(v,u);
        mn=min(mn,dp[v]);
        siz[u]+=siz[v];
        sum[u]+=sum[v];
    }
    dp[u]=min(sum[u]/siz[u],mn);
}
void solve() {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)h[i]=-1;
    for(int i=1;i<=n;i++)dp[i]=siz[i]=sum[i];
    idx=0;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        add(u,v),add(v,u);
    }
    dfs(1,1);
    for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}