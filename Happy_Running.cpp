#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
using ld = long double;
void solve() { 
    ld ans = 0;
    int k,x;
    cin>>k>>x;
    if(k == x) {
        ans = 0.5;
    }
    else if( k >= 2*x) {
        ans = 0;
    }
    else if(k > x) {
        ans = (2*x - k)*(2*x - k + 0.0)/2/ x / x;
    }
    else {
        ans = (x*x - k*k + 0.0) / x / x/2 + 0.5;
    }
    printf("%.2Lf\n",ans);
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