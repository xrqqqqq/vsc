#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N],mp[N];
array<int,2> t[N];
int unit;
struct node{
    int l,r,t,id;
    bool operator<(const node &x) {
        if(l/unit != x.l/unit) return l < x.l;
        if(r/unit != x.r/unit) return r < x.r;
        return t < x.t;
    }
};
int ans;
int res[N];
void add(int x) {
    x = a[x];
    if(mp[x] == 0) {
        ans++;
    }
    mp[x]++;
}
void del(int x) {
    x = a[x];
    if(mp[x] == 1) {
        ans--;
    }
    mp[x]--;
}
int l,r;
void upd(int tt) {
    auto [id,val] = t[tt];
    if(id >= l&&id <= r) {
        del(id);
        a[n+1] = val;
        add(n+1);
    } 
    swap(a[id],t[tt][1]);
}
void solve() {
    cin>>n >> m;
    unit = pow(n,2.0/3.0);
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    vector<node> tem;
    int tt = 0;
    for(int i = 1; i <= m; ++i) {
        char c;
        int x,y;
        cin>>c>>x>>y;
        res[i] = -1;
        if(c == 'Q') {
            tem.push_back({x,y,tt,i});
        }
        else {
            t[++tt] = {x,y};
        }
    }
    l = 1,r = 0;
    int t = 0;
    sort(tem.begin(),tem.end());
    for(auto &p : tem) {
        auto [ll,rr,tt,id] = p;
        while(l < ll) del(l++);
        while(l > ll) add(--l);
        while(r < rr) add(++r);
        while(r > rr) del(r--);
        while(t < tt) upd(++t);
        while(t > tt) upd(t--);
        res[id] = ans;
    }
    for(int i = 1; i <= m; ++i) {
        if(res[i] != -1) {
            cout<<res[i]<<"\n";
        }
    }
    
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