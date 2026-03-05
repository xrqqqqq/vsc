
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n ;
    map<int,int> ha;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        ha[a[i]]++;
    }
    int ans = 0;
    for(auto [x,y] : ha) {
        if(y >= 2) {
            ans += y*(y-1)/2*(n-y);
        }
    }
    cout<<ans<<"\n";
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