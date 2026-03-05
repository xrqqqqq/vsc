#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,w;
const int N = 2e5 + 10;
int b[N];
int a[N];
void solve() {
    cin>>n>>m>>k>>w;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    for(int i = 1; i <= m; ++i) cin>>b[i];
    b[m+1] = 0;
    b[m+2] = w + 1;
    
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