#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
vector<int>G[N];
int a[N];
int aa[N];
int vis[N];
int n;
int tmp=1;
vector<array<int,2>>ans;
bool cmp(int x,int y){
    return a[x]<a[y];
}
void dfs(int u){
    vis[u]=1;
    tmp++;
    if(tmp>n){
        return;
    }
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v])continue;
        if(aa[tmp]==v){
            dfs(v);
            if (tmp > n) {
                return;
            }
        }else{
            ans.push_back({u,aa[tmp]});
            dfs(aa[tmp]);
            if (tmp > n) {
                return;
            }
            i--;
        }
    }
    // while(u==aa[1]&&tmp<=n){
    //     ans.push_back({u,aa[tmp]});
    //     dfs(aa[tmp]);
    //      if(tmp>n){
    //         return;
    //     }
    // }
}
void test(){
    int m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        int u;cin>>u;
        a[u]=i;
        aa[i]=u;
    }
    for(int i=1;i<=n;i++){
        sort(G[i].begin(),G[i].end(),cmp);
    }
    while(tmp<=n)dfs(aa[tmp]);
    cout<<ans.size()<<'\n';
    for(auto [u,v]:ans){
        cout<<u<<' '<<v<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T=1;
    while(T--){
        test();
    }
    return 0;
}