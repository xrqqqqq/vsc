#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
int si;
void dfs(int u,int fa,int last) {
    if(si == 1) {
        a[u] = 1;
    }
    else {
        if(last == 2*si - 2||last == 2*si-3) {
            a[u] = last+1;
        }
        else {
            if(last  % 2 == 2*si % 2) {
                a[u] = 2*si;
            }
            else {
                a[u] = 2*si - 1;
            }
        }
    }
    ++si;
    for(auto i : ne[u]) {
        if(i == fa) continue;
        dfs(i,u,a[u]);
    }
}
void solve() {
    cin>>n;
    for(int i = 1; i<= n; ++i) ne[i].clear();
    for(int i = 0; i < n - 1; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    si = 1;
    dfs(1,-1,0);
    for(int i = 1; i <= n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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