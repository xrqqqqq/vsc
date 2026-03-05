#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
int sum[N][40];
int ans;
int x;
int id[N];
int f(vector<int> &p) {
    if(p.size() == 0) {
        return n - 1;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        bool v = 1;
        for(auto j : p) {
            if(sum[i][j] == 0) v = 0;
        }
        ans += v;
    }
    
    return ans;
}
void dfs(int u,int v,vector<int> &p) {
    if(u < 0) {
        ans = max(f(p),ans);
        return ;
    }
    if(v) {
        ans = max(f(p),ans);
        return ;
    }
    int now = id[u];
    int t = (x >> u) & 1ll;
    if(now == t) {
        if(t == 1) {
            dfs(u - 1, 0, p);
            p.push_back(u);
            dfs(u-1,1,p);
            p.pop_back();
        }
        else {
            dfs(u-1,0,p);
        }
    }
    else {
        if(now == 1) {
            p.push_back(u);
            dfs(u-1,0,p);
            p.pop_back();
        }
        else {
            dfs(u-1,1,p);
        }
    }
}
void solve() {
    cin>>n>>x;
    ans = 0;
    for(int i = 0; i <= 29; ++i) id[i] = 0;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    for(int i = 29; i >= 0; --i) {
        for(int j = 1;j <= n; ++j) sum[j][i] = 0;
    }
    int ned = 0;
    for(int i = 29; i >= 0; i--) {
        int cnt1 = 0;
        for(int j = 1; j <= n; ++j) {
            if((a[j] >> i) & 1ll) {
                cnt1++;
            }
        }
        if((cnt1 & 1ll)) {
            for(int j = 1; j <= n - 1; ++j) sum[j][i] = 1;
            ned += (1ll<<i);
            id[i] = 0;
        }
        else if(cnt1 != 0){
            id[i] = 1;
            int cnt = 0;
            for(int j = 1; j <= n - 1; ++j) {
                cnt += ((a[j] >> i) & 1ll);
                if(cnt % 2 == 0) {
                    sum[j][i] = 1;
                }
                else {
                    sum[j][i] = 0;
                }
            }
        }
        else {
            id[i] = 0;
            for (int j = 1; j <= n - 1; ++j) sum[j][i] = 1;
        }
    } 
    if(x < ned) {
        cout<<-1<<"\n";
    }
    else {
        x -= ned;
        vector<int> p;
        dfs(29,0,p);
        cout<<ans+1<<"\n";
    }
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