#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, k;
int a[N];
int b[N];
#define ld long double
void solve() {
    cin >> n >> k >> m;
    a[0] = b[0] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> b[i];
    }
    while (m--) {
        int x;
        cin >> x;
        int l = 0, r = k;
        while (l < r) {
            int m = l + r >> 1;
            if (x <= a[m])
                r = m;
            else
                l = m + 1;
        }
        if (x == 0) {
            cout << 0 << " ";
            continue;
        }
        if(a[r] == x) {
            cout<<b[r]<<" ";
            continue;
        }
        ld ans =
             ((ld)b[r - 1] * (a[r] - a[r - 1]) +
            ((ld)x - a[r - 1]) * (b[r] - b[r - 1]) + 0.0) / ((ld)a[r] - a[r - 1] + 0.0);
        cout << (int)ans << " ";
    }
    cout << "\n";
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