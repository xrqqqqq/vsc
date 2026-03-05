#include <bits/stdc++.h>
using namespace std;
#define int long long
#define a2 array<int, 2>
const int N = 1e6 + 10;
int n, m, k;
// int a[N];
a2 a[N];
a2 b[N];
void solve() {
    cin>> n >> m;
    int le1 = 0,le2 = 0;
    for(int i = 1;i <= n; ++i) {
        int c,w,f;
        cin>>c>>w>>f;
        if(w == 2) {
            a[le1++] = {f,c*w};
        }
        else {
            a[le1++] = {f,c*w};
        }
    }
    sort(a,a+le1);
    int last = 0,lf = 0;
    int ans = 0;
    int k = 0;
    last = 0;
    for(int i = le1 - 1; i >= 0; --i) {
        if(k == 0) {
            if(a[i][1] % m == 0) {
                ans += a[i][1] / m * a[i][0];
            }
            else {
                ans += a[i][1] / m * a[i][0];
                k = a[i][1] % m;
                last = a[i][0];
            }
        }
        else {
            if(a[i][1] + k >= m) {
                ans += last;
                a[i][1] -= m - k;
                k = 0;
                last = 0;
                if (a[i][1] % m == 0) {
                    ans += a[i][1] / m * a[i][0];
                } else {
                    ans += a[i][1] / m * a[i][0];
                    k = a[i][1] % m;
                    last = a[i][0];
                }
            }
            else {
                k += a[i][1];
            }
        }
    }
    if(k) {
        ans += last;
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