#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int v[N];
vector<int> ne[N];
int mod = 998244353;
int dfs(int x,int fa) {
    if(v[x]) return 2;
    v[x] = 1;
    bool vv = 0;
    for(auto y : ne[x]) {
        if(y == fa) continue;
        int res = dfs(y,x);
        if(res == 2) vv = 1;
    }
    if(vv) v[x] = 2;
    return v[x];
}
int p[N];
int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return x;
}
bool vv;
int dfss(int x,int fa) {
    if(v[x] == 3) return 0;
    v[x] = 3;
    int res = 1;
    for(auto y : ne[x]) {
        if(y == fa) continue;
        if(v[y] == 2) {
            int xx = find(x);
            int yy = find(y);
            if(xx != yy) {
                p[xx] = yy;
            }
            res += dfss(y,x);
        }
    }
    return res;
}
void solve() { 
    cin>>n>>m>>k;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        v[i] = 0;
        ne[i].clear();
    }
    vv = 0;
    for(int i = 1; i <= m ; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    dfs(1,-1);
    int ans = 1;
    unordered_map<int, int> cnt1;
    for(int i = 1; i <= n; ++i) {
        // cout<<v[i]<<" ";
        if(v[i] == 1&&a[i] == -1) {
            ans = (ans * k) % mod;
        }
        else if(v[i] == 2){
            int re = dfss(i,-1);
            cout<<re<<"\n";
            if(re % 2 == 0) {
                cnt1[find(i)] = 1;
            }
        }
    }
  
    unordered_map<int,int> cnt;
    for(int i = 1; i <= n; ++i) {
        if(v[i] != 1) {
            int xx = find(i);
            if(a[i] != -1) {
                if(cnt.count(xx) && cnt[xx] != a[i]) {
                    cout<<"0\n";
                    return ;
                }
                if(cnt.count(xx) == 0&&a[i] != 0) cnt[xx] = a[i];
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(v[i] != 1) {
            int xx = find(i);
            if(cnt.count(xx) == 0&&cnt1[xx] == 1) {
                ans = (ans * k) % mod;
                cnt[xx] = 2;
            }
        }
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