#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int cnt[N];
int ans[N];
int unit;  // 块长，一般sqrt(n)
struct node {
    int l, r, id;
    bool operator<(const node &x) const {
        if (l / unit != x.l / unit) return l < x.l;
        // 注意下面两行不能写小于（大于）等于，否则会出错（详见下面的小细节）
        if ((l / unit) & 1) return r < x.r;
        return r > x.r;
    }
};
int sum;
void move(int pos, int sign) {
    if(sign == -1) {
        cnt[a[pos]]--;
        sum -= (cnt[a[pos]])*(cnt[a[pos]] - 1) / 2;
    }
    else {
        sum += (cnt[a[pos]])*(cnt[a[pos]] - 1) / 2;
        cnt[a[pos]]++;
    }
}
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    vector<node> t;
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin>>x>>y;
        t.push_back({x,y,i});
    }
    unit = sqrt((n + 0.0)/sqrt(m));
    unit = max(unit,1ll);
    sort(t.begin(),t.end());
    int l = 1,r = 0;
    for(auto &q : t) {
        while(l < q.l) move(l++,-1);
        while(l > q.l) move(--l,1);
        while (r > q.r) move(r--, -1);
        while (r < q.r) move(++r, 1);
        ans[q.id] = sum;
    }
    for(int i = 1; i <= m;++i) {
        cout<<ans[i]<<"\n";
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