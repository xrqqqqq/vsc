#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
map<string, int> ha = {{"Ocelot", 1}, {"Serval", 2}, {"Lynx", 3}};
int n, m, k;
int a[N];
void solve() {
    cin>>n;
    int mi = 1;
    vector<int> cnt(n+1);
    for(int i = 1; i <= n; ++i) {
        cnt[i]++;
    }
    cin>>m;
    while(m--) {
        int x,y;
        cin>>x>>y;
        if(x >= mi) {
            int ans = 0;
            for(int i = mi; i <= x; ++i) ans += cnt[i];
            cout<<ans<<"\n";
            cnt[y] += ans;
            mi = x + 1;
        }
        else {
            cout<<0<<"\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    while (T--) {
        solve();
    }
}