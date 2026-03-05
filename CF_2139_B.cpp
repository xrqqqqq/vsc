#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0 ;
    int get = m;
    for(int i = n; i >= 1&&m > 0; --i,--m) {
        ans += a[i]*m;
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