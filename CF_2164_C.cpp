
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int b[N];
int c[N];
int n, m, k;
void solve() {
    cin >> n >> m;
    vector<array<int, 2>> te;
    multiset<int> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
        // mx = max(a[i], mx);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    vector<int> c0;
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
        if (c[i] == 0)
            c0.push_back(b[i]);
        else
            te.push_back({b[i], c[i]});
    }
    sort(te.begin(),te.end());
    int ans = 0;
    for(auto [x,y] : te) {
        auto p = s.lower_bound(x);
        if(p == s.end()) continue;
        auto t = *p;
        s.erase(p);
        t = max(t,y);
        s.insert(t);
        ans++;
    }
    sort(c0.begin(),c0.end());
    for(auto x : c0) {
        auto p = s.lower_bound(x);
        if(p == s.end()) continue;
        s.erase(p);
        ans++;
    }
    cout<<ans<<"\n";
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