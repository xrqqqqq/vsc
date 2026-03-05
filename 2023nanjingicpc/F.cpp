#include <bits/stdc++.h>
using namespace std;
#define int long long
#define a2 array<int, 2>
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int b[N];
vector<int> ne[N];
void solve() {
    cin>>n >> m;
    for (int i = 1; i <= n; ++i) ne[i].clear(), a[i] = 0;
    for(int i = 1; i <= n; ++i) {
        int si;
        cin>>si;
        for(int j = 1; j <= si; ++j) {
            int x;
            cin>>x;
            ne[i].push_back(x);
            a[x] = i;
        }
    }
    for(int i = 1; i <= n; ++i) {
        b[i] = i;
    }
    // int now = 1;
    for(int i = 1; i < n; ++i) {
        bool v = 1;
        for(auto j : ne[i]) {
            if(a[j] == i + 1) {
                v = 0;
                break;
            }
        }
        if(v) {
            cout<<"Yes\n";
            swap(b[i],b[i+1]);
            for(int i = 1; i <= n; ++i) {
                cout<<b[i]<<" ";
            }
            cout<<"\n";
            return ;
        }
    }
    cout<<"No\n";
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