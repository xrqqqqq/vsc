
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m;
vector<int> ne[N];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        ne[i].clear();
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = i; j <= m; j += i) {
            ne[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 2; i <= n; ++i) {
        for(int j = i; j <= m; j *= i) {
            cout<<j<<" ";
        }
        cout<<"\n";
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