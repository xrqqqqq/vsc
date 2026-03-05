#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int a[N];
int n, m, k;
int dfs(int len,vector<int> &a) {
    vector<int> b[2];
    for(auto x : a) {
        if(x & (1ll << len)) b[1].push_back(x^(1ll<<len));
        else b[0].push_back(x);
    }
    if(len == 0) {
        if(b[0].size() == 0) return 0;
        else if(b[1].size()) return 1;
        return 0;
    }
    if(b[0].size() == 0) return dfs(len-1,b[1]);
    else if(b[1].size() == 0) return dfs(len-1,b[0]);
    else {
        return (1ll << len) + min(dfs(len-1,b[0]),dfs(len-1,b[1]));
    }
}
void solve() {
    cin>>n;
    vector<int> cnt;
    int mx = 0;
    for(int i = 0; i < n; ++i) cin>>k,cnt.push_back(k),mx = max(mx,k); 
    int len = log2(mx);
    if(mx == 0) len = 0;
    cout<<dfs(len,cnt);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}