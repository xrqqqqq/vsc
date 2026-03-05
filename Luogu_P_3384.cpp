#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int a[N];
int w[N],cnt;
int fa[N],son[N],siz[N],top[N],dep[N],id[N];
vector<int> ne[N];

int p;
int n,m,k;
struct node{
    int sum[N<<2],ad[N<<2];
    #define ls (u << 1)
    #define rs (u << 1 | 1)
    void up(int u) {
        sum[u] = (sum[ls] + sum[rs])%p;
    }
    void down(int u,int l,int r) {
        if(ad[u]) {
            int mid = l + r >> 1;
            ad[ls] = (ad[ls] + ad[u])%p;
            sum[ls] = (sum[ls] + (mid - l + 1)*ad[u]%p)%p;
            ad[rs] = (ad[rs] + ad[u])%p;
            sum[rs] = (sum[rs] + (r - mid)*ad[u]%p)%p;
            ad[u] = 0;
        }
    }
    void build(int u,int l,int r) {
        if(l == r) {
            sum[u] = w[l]%p;
            return ;
        }
        int mid = l + r >> 1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        up(u);
    }
    void change(int u,int l,int r,int L,int R,int c) {
        if(L <= l && r <= R) {
            sum[u] = (sum[u] + (r-l+1)*c%p)%p;
            ad[u] = (ad[u] + c)%p;
            return ;
        }
        int mid = l + r >> 1;
        down(u,l,r);
        if(L <= mid) change(ls,l,mid,L,R,c);
        if(mid < R) change(rs,mid+1,r,L,R,c);
        up(u);
    }
    int ask(int u,int l,int r,int L,int R) {
        if(L <= l && r <= R) {
            return sum[u];
        }
        int res = 0;
        int mid = l + r >> 1;
        down(u,l,r);
        if(L <= mid) res = (res + ask(ls,l,mid,L,R))%p;
        if(mid < R) res = (res + ask(rs,mid+1,r,L,R))%p;
        return res;
    }
}tr;
void dfs1(int u, int f) {
    fa[u] = f;
    siz[u] = 1;
    int mxsi = 0;
    for (auto i : ne[u]) {
        if (i == f) continue;
        dep[i] = dep[u] + 1;
        dfs1(i, u);
        siz[u] += siz[i];
        if (siz[i] > mxsi) {
            mxsi = siz[i];
            son[u] = i;
        }
    }
}
void dfs2(int u, int f) {
    id[u] = ++cnt;
    w[cnt] = a[u];
    top[u] = f;
    if (son[u] == 0) return;
    dfs2(son[u], f);
    for (auto i : ne[u]) {
        if (i == fa[u] || i == son[u]) continue;
        dfs2(i, i);
    }
}
int ask(int a,int b) {
    int res = 0;
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a,b);
        res = (res + tr.ask(1,1,n,id[top[a]],id[a]))%p;
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a,b);
    res = (res + tr.ask(1,1,n,id[b],id[a]))%p;
    return res;
}
void sset(int a,int b,int c) {
    while(top[a] != top[b]) {
        if(dep[top[a]] < dep[top[b]]) swap(a,b);
        tr.change(1,1,n,id[top[a]],id[a],c);
        a = fa[top[a]];
    }
    if(dep[a] < dep[b]) swap(a,b);
    tr.change(1,1,n,id[b],id[a],c);
}
void solve() {
    cin>>n>>m>>k>>p;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    for(int i = 0; i < n - 1; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    dfs1(k,k);
    dfs2(k,k);
    tr.build(1,1,n);
    while(m--) {
        int op;
        cin>>op;
        if(op == 1) {
            int x,y,z;
            cin>>x>>y>>z;
            sset(x,y,z);
        }
        else if(op == 2) {
            int x,y;
            cin>>x>>y;
            cout<<ask(x,y)<<"\n";
        }
        else if(op == 3) {
            int x,z;
            cin>>x>>z;
            tr.change(1,1,n,id[x],id[x] + siz[x]-1,z);
        }
        else {
            int x;
            cin>>x;
            cout<<tr.ask(1,1,n,id[x],id[x] + siz[x]-1)<<"\n";
        }
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