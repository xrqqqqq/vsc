#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int mod = 1e9 + 7;
int f[N];
int nf[N];
int ksm(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
int C(int a, int b) {
    if (a < b) return 0;
    return f[a] * nf[b] % mod * nf[a - b] % mod;
}
int A(int a, int b) { return f[a] * nf[a - b] % mod; }
void solve() {
    cin >> n >> m;
    if (m > (1ll << n) - 1) {
        cout << -1 << "\n";
        return;
    }
    if (m == 0) {
        for (int i = 0; i < (1ll << n); ++i) {
            cout << i << " " << i << " ";
        }
        return;
    }
    vector<int> v;
    for (int i = 0; i < (1ll << n); ++i) {
        if (i == m) {
            continue;
        }
        v.push_back(i);
        // cout<<i<<" ";
    }
    int res = 0;
    // cout<<m<<" ";
    v.push_back(m);
    for (int i = (1ll << n) - 1; i >= 0; --i) {
        if (i == m) {
            continue;
        }
        // cout<<i<<" ";
        v.push_back(i);
        res ^= i;
    }

    if (res != m) {
        cout << -1 << "\n";
        return;
    }
    for (auto i : v) {
        cout << i << " ";
    }
    cout << m << "\n";
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