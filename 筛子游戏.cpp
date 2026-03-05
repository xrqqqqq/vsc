#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, k;
int k1,k2,k3;
int a,b,c;
// int a[N];
using ld = long double;
ld f[N];
ld p[N];
ld A[N];
ld B[N];
void solve() {
    cin>>n>>k1>>k2>>k3>>a>>b>>c;
    int k = k1 + k2 + k3;
    int si = k1*k2*k3;
    p[0] = 1.0/si;
    for(int su = 1; su <= k; ++su) {
        int cnt = 0;
        for(int i = 1; i <= k1; ++i) {
            for(int j = 1; j <= k2; ++j) {
                for(int k = 1; k <= k3; ++k) {
                    if(i + j + k == su&&!(i == a&&j == b && k == c)) {
                        cnt++;
                    }
                }
            }
        }
       
        p[su] = cnt*1.0/si;
    }
    for(int i = n; i >= 0; --i) {
        A[i] = p[0];
        B[i] = 1;
        for(int ad = 1; ad <= k; ++ ad) A[i] += A[i+ad]*p[ad],B[i] += B[i + ad]*p[ad];
    }
    ld ans = B[0] / (1.0 - A[0]);
    printf("%.10Lf",ans);
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