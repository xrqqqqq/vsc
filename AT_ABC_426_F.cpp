#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
int inf = 1e18;
struct tr{
    int cnt[N<<2],mi[N<<2],tagk[N<<2];
    #define ls (u << 1)
    #define rs (u << 1 | 1)
    void up(int u) {
        cnt[u] = cnt[ls] + cnt[rs];
        mi[u] = min(mi[ls],mi[rs]);
    }
    void down(int u) {
        if(tagk[u]) {
            tagk[ls] += tagk[u];
            mi[ls] -= tagk[u];
            tagk[rs] += tagk[u];
            mi[rs] -= tagk[u];
            tagk[u] = 0;
        }
    }
    void build(int u,int l,int r) {
        if(l == r) {
            cnt[u] = 1;
            mi[u] = a[l];
            return ;
        }
        int mid = l + r >> 1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        up(u);
    }
    int change(int u,int l,int r,int L,int R,int k) {
        if(L <= l&&r <= R&&mi[u] > k) {
            mi[u] -= k;
            tagk[u] += k;
            return cnt[u]*k;
        }
        if(l == r) {
            int res = mi[u];
            mi[u] = inf;
            cnt[u] = 0;
            return res;
        }
        int res = 0;
        down(u);
        int mid = l + r >> 1;
        if(L <= mid) res += change(ls,l,mid,L,R,k);
        if(mid < R) res += change(rs,mid+1,r,L,R,k);
        up(u);
        return res;
    }
}t;
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    cin>>m;
    t.build(1,1,n);
    while(m--) {
        int l,r,k;
        cin>>l>>r>>k;
        // cout<<"fd\n";
        cout<<t.change(1,1,n,l,r,k)<<"\n";
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