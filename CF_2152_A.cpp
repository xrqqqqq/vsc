#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
void solve() {
    map<int,int> ha;
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        ha[x];
    }
    int t = ha.size();
    cout<<t+max(0ll,t-1)<<"\n";
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