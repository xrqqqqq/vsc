#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n, m, k;
int a[N];
#define int long long
using ld = long double;
ld f[N][N];
void solve() {
    ld p1,p2,p3,p4;
    cin>> n >> m >> k >> p1 >> p2 >> p3 >> p4;
    f[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(j == 1) {
                  
            }
        }
    }
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
