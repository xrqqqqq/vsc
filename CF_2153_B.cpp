#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    int x,y,z;
    cin>>x>>y>>z;
    int t = max({x,y,z});
    int tt = log2(t);
    for(int i = tt; i >= 0; --i) {
        int c1 = 0,c0 = 0;
        if(((x >> i )&1ll) == 0) c0++;
        if (((y >> i) & 1ll) == 0) c0++;
        if (((z >> i) & 1ll) == 0) c0++;
        if(c0 == 1) {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
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