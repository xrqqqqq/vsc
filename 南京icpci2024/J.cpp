#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n,m,k;cin>>n>>m>>k;
    vector<int>vis(k+1);
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        vis[t]++;
    }
    int ans=0;
    vector<map<int,int>>mp(k+1);
    vector<vector<int>>g(k+1);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        if(vis[u]&&vis[v]){
            ans++;
        }else{
            mp[u][v]++;
            if(mp[u][v]==1)g[u].push_back(v);
            if(v!=u)mp[v][u]++;
            if (mp[v][u] == 1 && v != u) g[v].push_back(u);
        }
    }
    // cout<<ans<<'\n';
    vector<int>val(k+1);
    for(int i=1;i<=k;i++){
        if(vis[i])continue;
        for(auto u:g[i]){
            if(vis[u])val[i]+=mp[i][u];
            if(u==i)val[i]+=mp[i][i];
        }
    }
    // for(int i=1;i<=k;i++){
    //     cout<<val[i]<<' ';
    // }
    // cout<<'\n';
    int mx1=0,mx2=0;
    for(int i=1;i<=k;i++){
        if(mx1<val[i]){
            mx2=mx1,mx1=val[i];
        }else if(mx2<val[i]){
            mx2=val[i];
        }
    }
    int ans1=ans+mx1+mx2;
    for(int i=1;i<=k;i++){
        if(!vis[i]){
            for(auto v:g[i]){
                if(!vis[v]&&v!=i){
                    ans1=max(ans1,ans+val[i]+val[v]+mp[i][v]);
                }
            }
        }
    }
    cout<<ans1<<'\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}