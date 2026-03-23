#include <bits/stdc++.h>
using namespace std;
#define int long long

int ksm(int a, int b) {
    int sum = 1;
    while (b) {
        if (b & 1) sum *= a;
        a *= a;
        b >>= 1;
    }
    return sum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (k >= 18) {
        cout << 1 << '\n';
        return;
    }
    for (int i = 1; i * i <= n; i++) {
        if (ksm(i, k) <= n && ksm(i + 1, k) > n) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}