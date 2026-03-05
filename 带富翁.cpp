#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
using ld = long double;
ld f[N];
void solve() {
    cin>>n;
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    f[n]  = a[n];
    for(int i  = n - 1; i >= 1; --i) {
        if(i + 6 > n) {
            for(int j = i + 1; j <= n; ++j) {
                f[i] += f[j];
            }
            f[i] /= (n-i);
            f[i] += a[i];
        }
        else {
            for(int j = i + 1;j <= i + 6; ++j) {
                f[i] += f[j]/6;
            }
            f[i] += a[i];
        }
    }
    printf("%.10Lf\n",f[1]);
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