#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int l, r;
int ans;
int L = 0;
void f(int l, int r, int ba) {
    if (l > r) return;
    if (l == r) {
        a[l + ba - L] = l + ba;
        return;
    }
    int t = log2(r);
    if (l < (1 << t)) {
        int rr = (1 << t);
        int ll = rr - 1;
        for (; ll >= l && rr <= r; ++rr, --ll) {
            a[rr + ba - L] = ll + ba;
            a[ll + ba - L] = rr + ba;
        }
        f(l, ll, ba);
        f(rr, r, ba);
    } else {
        f(l - (1 << t), r - (1 << t), ba + (1 << t));
    }
}
void solve() {
    cin >> l >> r;
    ans = 0;
    L = l;
    f(l, r, 0);
    int ans1 = 0;
    for (int i = 0; i <= r - l; ++i) {
        ans1 += (a[i] | (i + L));
    }
    cout << ans1 << "\n";
    for (int i = 0; i <= r - l; ++i) {
        cout<<a[i]<<" ";
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