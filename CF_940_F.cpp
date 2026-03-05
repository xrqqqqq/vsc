#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
//[P1903 [国家集训队] 数颜色 / 维护队列 -
// 洛谷](https://www.luogu.com.cn/problem/P1903)
int unit;
struct node {
    int l, r, t, id;
    bool operator<(const node &x) {
        if (l / unit != x.l / unit) return l < x.l;
        if (r / unit != x.r / unit) return r < x.r;
        return t < x.t;
    }
};
array<int, 2> t[N];
vector<int> tee;
int mp[N];
int te[N];
int re[N];
int ans = 1;
int res[N];
set<int> s;
int f(int x) {
    return lower_bound(tee.begin(),tee.end(),x) - tee.begin();
}
void add(int x) {
    x = a[x];
    int last = mp[x];
    te[mp[x]]--;
    mp[x]++;
    te[mp[x]]++;
    int now = mp[x];
    if (te[last] == 0) {
        s.insert(last);
    }
    if (te[now] == 1) {
        s.erase(now);
    }
    ans = *s.begin();
}
void del(int x) {
    x = a[x];
    int last = mp[x];
    te[mp[x]]--;
    mp[x]--;
    te[mp[x]]++;
    int now = mp[x];
    if (te[last] == 0) {
        s.insert(last);
    }
    if (te[now] == 1) {
        s.erase(now);
    }
    ans = *s.begin();
}
int l, r;
void upd(int tt) {
    auto [id, val] = t[tt];
    if (id >= l && id <= r) {
        del(id);
        a[n + 1] = val;
        add(n + 1);
    }
    swap(a[id], t[tt][1]);
}
void solve() {
    cin >> n >> m;
    unit = pow(n, 0.6666666);
    for (int i = 0; i <= n + 1; ++i) {
        s.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tee.push_back(a[i]);
    }
    vector<node> tem;
    int tt = 0;
    for (int i = 1; i <= m; ++i) {
        int c;
        int x, y;
        cin >> c >> x >> y;
        res[i] = -1;
        if (c == 1) {
            tem.push_back({x, y, tt, i});
        } else {
            t[++tt] = {x, y};
        }
        tee.push_back(y);
    }
    sort(tee.begin(),tee.end());
    tee.erase(unique(tee.begin(),tee.end()),tee.end());
    for(int i = 1; i <= n; ++i) {
        a[i] = f(a[i]);
    }
    for(int j = 1; j <= tt; ++j) {
        t[j][1] = f(t[j][1]);
    }
    l = 1, r = 0;
    int t = 0;
    te[0] = 1e9 + 10;
    s.erase(0);
    sort(tem.begin(), tem.end());
    for (auto &p : tem) {
        auto [ll, rr, tt, id] = p;
        while (l < ll) del(l++);
        while (l > ll) add(--l);
        while (r < rr) add(++r);
        while (r > rr) del(r--);
        while (t < tt) upd(++t);
        while (t > tt) upd(t--);
        res[id] = *(s.begin());
    }
    for (int i = 1; i <= m; ++i) {
        if (res[i] != -1) {
            cout << res[i] << "\n";
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