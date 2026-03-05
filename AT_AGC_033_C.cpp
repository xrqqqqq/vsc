#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
int len,mxid;
void dfs(int u,int dep,int fa) {
    // cout<<u<<" "<<dep<<"\n";
    if(dep > len) {
        len = dep;
        mxid = u;
    }
    for(auto i : ne[u]) {
        if(i == fa) continue;
        dfs(i,dep+1,u);
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
    len = 0;
    dfs(1,1,-1);
    len = 0;
    dfs(mxid,1,-1);
    if(len%3 == 2) {
        cout<<"Second\n";
    }
    else {
        cout<<"First\n";
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