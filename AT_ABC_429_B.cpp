
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n >> m;
    vector<int> sum(n+1);
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(sum[n] - a[i] == m) {
            cout<<"Yes\n";
            return ;
        }
    }
    cout<<"No";
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