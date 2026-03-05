#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];

void solve() { 
    map<int, int> ha; 
    cin>>n;
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        ha[a[i]]++;
        mx = max(ha[a[i]],mx);
    }
    int ans = 0;
    for(int i  =1; i <= mx; ++i) {
        int len  = 0;
        for(auto [x,y] : ha) {
            if(y >= i) len++;
        }
        ans = max(ans,len*i);
    }
    cout<<ans<<"\n";
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