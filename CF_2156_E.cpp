
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
#define a2 array<int,2> 
vector<int> ne[N];
set<a2> s;
int n;
int a[N];
bool check(int x) {
    for(int i = 1; i <= n; ++i) ne[i].clear();
    s.clear();
    for(int i = 1; i <= n; ++i) {
        for(auto [t,id] : s) {
            if(a[i] - t >= x) {
                ne[i].push_back(id);
                ne[id].push_back(i);
            }
        }
        s.insert({a[i],i});
        if(s.size() > 3) {
            auto p = s.end();
            p--;
            s.erase(p);
        }
    }
    int ned = 0;
    for(int i = 1; i <= n; ++i) ned += (int)ne[i].size() >= 2;
    if(ned == 0) return 0;
    for(int i = 1; i <= n; ++i) {
        int sum = (int)ne[i].size() >= 2;
        for(auto j : ne[i]) {
            if(ne[j].size() == 2) sum++;
        }
        if(sum >= ned) {
            return 0;
        }
    }   
    return 1; 
}
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
  
    int l = -1e9,r = 1e9;
    while(l < r) {
        int m = l + r+ 1 >> 1;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout<<l<<"\n";
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