#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int mod = 998244353;
int a[N];
int b[N];
int f(int a[], int x) {
    int ans = 1e18;
    vector<int> sum(n + 2);
    vector<int> cnt(n + 2);
    for (int i = 1; i <= n; ++i) {
        if (i == 1)
            sum[i] = 0;
        else
            sum[i] = sum[i - 1] + abs(a[i] - a[i - 1]) * cnt[i - 1];
        cnt[i] = cnt[i - 1] + 1;
    }
    int tem = 0;
    int c = 0;
    for (int i = n; i >= 1; --i) {
        if (i == n)
            tem = 0;
        else
            tem = tem + abs(a[i + 1] - a[i]) * c;
        int re = a[i] - x;
        int id = upper_bound(a + 1, a + 1 + n, re) - a;
        id--;
        int res = sum[id] + tem + abs(a[id] - re) * cnt[id];
        if (id == 0) res = tem;
        // cout<<res<<"\n";
        ans = min(ans, res);
        c++;
    }
    sum.assign(n + 2, 0);
    cnt.assign(n + 2, 0);
    for (int i = n; i >= 1; --i) {
        if (i == n)
            sum[i] = 0;
        else
            sum[i] = sum[i + 1] + abs(a[i + 1] - a[i]) * cnt[i + 1];
        cnt[i] = cnt[i + 1] + 1;
    }
    tem = 0;
    c = 0;
    for(int i = 1; i <= n; ++i) {
        if (i == 1)
            tem = 0;
        else
            tem = tem + abs(a[i] - a[i - 1]) * c;
        int re = a[i] + x;
        int id = upper_bound(a + 1, a + 1 + n, re) - a;
        int res = sum[id] + tem + abs(a[id] - re) * cnt[id];
        if(a[id] <= re) id = n + 1;
        if (id == n + 1) res = tem;
        // cout<<res<<"\n";
        ans = min(ans, res);
        c++;
    }
    return ans;
}
bool check(int x) {
    int t1 = f(a, x);
    int t2 = f(b, x);
    // cout<<t1<<" "<<t2<<"\n";
    return t1 + t2 <= k;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int l = 0, r = 1e9 + 100;
    // cout<<check(1);
    while (l < r) {
        int m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
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