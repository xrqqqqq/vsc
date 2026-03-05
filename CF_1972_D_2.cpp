#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int f2(int a, int b) { return abs(a - b); }
int f3(int a, int b, int c) { return max({a, b, c}) - min({a, b, c}); }
void solve() {
    cin>>n>>m;
    int nn = sqrt(n);
    int mm = sqrt(m);
    int ans = 0;
    for(int i = 1; i <= nn;++i) {
        for(int j = 1; j <= mm; ++j) {
            if(__gcd(i,j) == 1) {
                ans += min(n/i,m/j)/(i+j);
            }
        }
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