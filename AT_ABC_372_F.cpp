#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int mod = 998244353;
int fix(int x) {
    return (x % mod + mod) % mod;
}
vector<array<int,2>> ne;
void solve() {
    cin>>n>>m>>k;
    while(m--) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        ne.push_back({x,y});
    }
    int ad = 0;
    vector<int> f(n+1);
    f[0] = 1;
    for(int i = 1; i <= k; ++i) {
        ad = (ad + n - 1)%n;
        map<int,int> to;
        for(auto [x,y] : ne) {
            x = (x + ad + 1)%n,y = (y + ad)%n;
            if(to.count(y) == 0) to[y] = f[y];
            to[y] = fix(to[y] + f[x]);
        }
        for(auto [x,y] : to) {
            f[x] = y;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) ans = fix(ans + f[i]);
    cout<<ans;
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