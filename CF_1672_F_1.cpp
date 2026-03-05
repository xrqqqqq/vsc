
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
vector<int> ne[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) ne[i].clear();
    vector<int> tem;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ne[a[i]].push_back(i);
        tem.push_back(a[i]);
    }
    auto f = [&](vector<int> & p) {
        if(p.size() == 1) return ;
        int t = a[p[0]];
        for(int i = 0; i < p.size() - 1; ++i) {
            a[p[i]] = a[p[i+1]];
        }
        a[p[p.size() - 1]] = t;
    };
    sort(tem.begin(),tem.end());
    tem.erase(unique(tem.begin(),tem.end()),tem.end());
    while(tem.size()) {
        vector<int> p;
        vector<int> te;
        for(auto i : tem) {
            if(ne[i].size()) {
                p.push_back(ne[i].back());
                ne[i].pop_back();
            }
            if(ne[i].size()) {
                te.push_back(i);
            }
        }
        f(p);
        tem = te;
    }
    for(int i = 1; i <= n; ++i) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
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