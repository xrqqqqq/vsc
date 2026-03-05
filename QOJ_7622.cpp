#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 3e5 + 10;
int n,m;
int a[N];
int b[N];
void test() {
    cin>>n >> m;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        b[i] = 0;
    }
    vector<int> v(n+1);
    int mx = n + 1;
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin>>x>>y;
        b[x] += y;
    }
    b[n+1] = 0;
    for(int i = n; i >= 1; --i) {
        b[i] += b[i+1];
    }
    vector<array<int,2>> te;
    for(int i = 1; i <= n; ++i) {
        te.push_back({a[i] - b[i],i});
    }
    sort(te.begin(),te.end());
    vector<int> ne;
    for(auto [y,id] : te) {
        if(id < mx) {
            ne.push_back(id);
            mx = id;
        }
    }
    int last = n + 1;
    for(auto id : ne) {
        a[id] -= (b[id] - b[last]);
        last = id;
    }
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= n; ++i) {
        a[i] += a[i-1];
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        test();
    }
    return 0;
}