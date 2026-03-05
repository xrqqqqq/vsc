#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int b[N];
void solve() {
    cin>>n;
    int mx = 2*n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin>>x;
        a[x] += i - 1;
    }
    for(int i = 1; i <= n; ++i) {
        a[i] += i*mx;
        b[i] += (n-i+1)*mx;
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    for(int i = 1; i <= n ; ++i ) {
         cout<<b[i] <<" ";
    }
    
    
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