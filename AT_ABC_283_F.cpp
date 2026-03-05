#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
int tr1[N],tr2[N];
int mx = 1e17;
int ask1(int u) {
    int res = -mx;
    for(;u; u -= (u&-u))  res = max(res,tr1[u]);
    return res;
}
void add1(int u,int c) {
    for (; u <= n; u += (u & -u)) tr1[u] = max(tr1[u], c);
}
int ask2(int u) {
    int res = mx;
    for (; u <= n; u += (u & -u)) res = min(res, tr2[u]);
    return res;
}
void add2(int u,int c) {
    for (; u; u -= (u & -u)) tr2[u] = min(tr2[u], c);
}
void init(int a[],int c) {
    for(int i = 1; i <= n; ++i) {
        a[i] = c;
    }
}
void solve() {
    cin>>n;
    init(tr1, -mx);
    init(tr2, mx);
    for(int  i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    vector<int> ans(n+1,mx);
    for(int i = 1; i <= n; ++i) {
        int t1 = ask1(a[i]);
        int t2 = ask2(a[i]);
        ans[i] = min(ans[i],a[i] + i - t1);
        ans[i] = min(ans[i],t2 - (a[i] - i));
        add1(a[i],a[i] + i);
        add2(a[i],a[i] - i);
    }
    init(tr1,-mx);
    init(tr2,mx);
    for(int i = n; i >= 1; --i) {
        int t1 = ask1(a[i]);
        int t2 = ask2(a[i]);
        ans[i] = min(ans[i],a[i] - i - t1);
        ans[i] = min(ans[i],t2 - (a[i] + i));
        add1(a[i],a[i] - i);
        add2(a[i],a[i] + i);
    }
    for(int i = 1; i <= n; ++i) {
        cout<<ans[i]<<" ";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}