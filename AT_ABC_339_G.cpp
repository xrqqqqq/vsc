#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int b[N];
int a[N];
int B;
int su[N];
int f(int l, int r, int x) {
    int ans = 0;
    int il = (l + B - 1) / B;
    int ir = (r + B - 1) / B;
    if (abs(il - ir) <= 1) {
        for (int i = l; i <= r; ++i) {
            ans += a[i] <= x ? a[i] : 0;
        }
        return ans;
    } else {
        int ans = 0;
        for (int i = l; i <= (il * B); ++i) {
            ans += a[i] <= x ? a[i] : 0;
        }
        for (int i = (ir - 1) * B + 1; i <= r; ++i) {
            ans += a[i] <= x ? a[i] : 0;
        }
        for (int j = il + 1; j <= ir - 1; ++j) {
            int ll = (j - 1) * B + 1;
            int rr = min(j * B, n);
            int pos = upper_bound(b + ll, b + rr + 1, x) - (b + ll);
            if (pos > 0) ans += su[pos + ll - 1];
        }
        return ans;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    B = sqrt(n*sqrt(n));
    int r = (n + B - 1) / B;
    for (int l = 1; l <= r; ++l) {
        int ll = (l - 1) * B + 1;
        int rr = min(l * B, n);
        sort(b + ll, b + rr + 1);
        int sum = 0;
        for (int j = ll; j <= rr; ++j) {
            sum += b[j];
            su[j] = sum;
        }
    }
    cin >> m;
    int xi  = 0;
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l = l ^ xi;
        r = r ^ xi;
        x = x ^ xi;
        x = f(l, r, x);
        xi = x;
        cout << x << "\n";
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