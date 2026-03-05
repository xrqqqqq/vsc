#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
int dp[N];
int f[N];
vector<int> ne[N];
int si[N];
int siid[N];
bool dfs(int u,int fa) {
    int res = 0;
    bool v = 0;
    for(auto i : ne[u]) {
        if(i == fa) continue;
        if(!dfs(i,u)) {
            v = 1;
            si[u]++;
            siid[u] = i;
        }
    }
    dp[u] = v;
    return v;
}
void dfss(int u,int fa) {
    for(int i : ne[u]) {
        if(i == fa) continue;
        if(dp[i]) {
            f[i] = 1;
            if (f[u] == 0)
                si[i]++;
            else if (si[u] == 1 && siid[u] == i) {
               si[i]++;
            }
        }
        else {
            if(f[u] == 0) f[i] = 1,si[i]++;
            else if(si[u] == 1 && siid[u] == i) {
                f[i] = 1;
                si[i]++;
            }
        }

        dfss(i,u);
    }
}
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n - 1; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    dfs(1,-1);
    f[1] = dp[1];
    dfss(1,-1);
    while(m--) {
        int x;
        cin>>x;
        if(f[x]) {
            cout<<"Ron\n";
        }
        else {
            cout<<"Hermione\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    // init(1e5);
    while (T--) {
        solve();
    }
}