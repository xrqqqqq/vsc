
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int inf = 1e10;
int v[N][3];
int ans[N];
#define a3 array<int,3>
vector<int> ne[N];
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin>>x>>y;
        ne[x].push_back(y);
        ne[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) {
        v[i][0] = v[i][1] =v[i][2]= inf;
    }
    string s;
    cin>>s;
    queue<a3> q; 
    for(int i = 1; i <= n; ++i) {
        if(s[i-1] == 'S') {
            a[i] = 0;
            v[i][0] = 0;
            v[i][2] = i;
            q.push({i,i,0});
        }
        else {
            a[i] = 1;
        }
    }
    while(q.size()) {
    
        auto [u,id,w] = q.front();
        q.pop();
        for(auto i : ne[u]) {
            if(v[i][0] == inf) {
              
                v[i][0] = w + 1;
                v[i][2] = id;
                q.push({i,id,w+1});
              
            }
            else if(v[i][1] == inf) {
                if(v[i][2] != id){
                    v[i][1] = w + 1;
                    q.push({i,id,w+1});
                   
                }
            }
            
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i]) {
            cout<<v[i][0] + v[i][1]<<"\n";
        }
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