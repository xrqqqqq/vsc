#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
set<int> ne[N];
int p[N];
int find(int x) {
    if(x != p[x]) return p[x] = find(p[x]);
    return x;
}
int v[N];
int d[N];
vector<array<int,3>> ans;
void f(int x,int y,int z) {
    ans.push_back({x,y,z});
    if(ne[x].count(y)) {
        ne[x].erase(y);
        ne[y].erase(x);
    }
    else {
        ne[x].insert(y);
        ne[y].insert(x);
    }
    if (ne[z].count(y)) {
        ne[z].erase(y);
        ne[y].erase(z);
    } else {
        ne[z].insert(y);
        ne[y].insert(z);
    }
    if (ne[x].count(z)) {
        ne[x].erase(z);
        ne[z].erase(x);
    } else {
        ne[x].insert(z);
        ne[z].insert(x);
    }

}
vector<int> nee[N];
map<array<int,3>,int> ha;
void dfs(int u,int p) {
    v[u] = p;
    for(auto i : nee[u]) {
        if (u != p && i != p) {
            if(ha[{p,u,i}] == 0) {
                f(p, u, i);
            }
            ha[{p,u,i}] = 1;
            ha[{p,i,u}] = 1;
        }
        if(!v[i]) {
            dfs(i,p);
        }
    }
}
void dfss(int u) {
    v[u] = 1;
    for(auto i : ne[u]) {
        if(v[i] == 0) {
            dfss(i);
        }
    }
}
void solve() {
    cin >> n>>m;
    
    ha.clear();
    ans.clear();
    for(int i = 1;i  <= n; ++i) ne[i].clear(),p[i] = i,v[i] = 0,d[i] = 0,nee[i].clear();
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].insert(y);
        ne[y].insert(x);
        d[x]++;
        d[y]++;
        nee[x].push_back(y);
        nee[y].push_back(x);
    }
    // if (m == 0 || m == n - 1) {
    //     cout << 0 << "\n";
    //     return;
    // }
    for(int i = 1; i <= n; ++i) {
        if(!v[i]) {
            // v[i] = i;
            dfs(i,i);
        }
    }
    int id = 0,si = 0;
    for(int i = 1; i <= n; ++i) {
        si += ne[i].size();
        v[i] = 0;
    }
    // cout<<si<<"\n";
    if(si == 0) {
        cout<<ans.size()<<"\n";
        for(auto i : ans) {
            cout<<i[0] <<" "<<i[1]<<" "<<i[2]<<"\n";
        }
    }
    else {
        vector<int> p;
        int o = 0;
        for(int i = 1; i <= n; ++i) {
            if(v[i] == 0) {
                if(ne[i].size()&&id == 0) {
                    id = *ne[i].begin();
                    o = i;
                    dfss(i);
                }
                else {
                    p.push_back(i);
                    dfss(i);
                }
            }
        }
        p.push_back(o);
        for(int i = p.size() - 1; i > 0; --i) {
            f(id,p[i],p[i-1]);
        }
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << i[0] << " " << i[1] << " " << i[2] << "\n";
        }
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