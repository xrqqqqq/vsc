#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int v[N];
vector<int> ne[N];
int su[N];
int f[N];
int dfs(int x,int fa,int dep) {
    int ans = 0;
    int sum = 0;
    for(auto y : ne[x]) {
        if(y == fa) continue;
        ans += dfs(y,x,dep + 1);
        sum += su[y];
    }
    ans += dep*a[x];
    f[x] = ans;
    su[x] = sum + a[x];
    return ans;
}
int ans;
int sc;
void dfss(int x,int fa) {
    ans = min(ans,f[x]);
    for(auto y : ne[x]) {
        if(y == fa) continue;
        f[y] = f[x] + sc - 2*su[y];
        dfss(y,x);
    }
}
void solve() {
    cin>>n;
    for(int i = 1; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    dfs(1,-1,0);
    ans = f[1];
    sc = su[1];
    dfss(1,-1);
    cout<<ans<<"\n";
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