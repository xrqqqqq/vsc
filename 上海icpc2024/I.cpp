#include <bits/stdc++.h>
using namespace std;
// const int N = 1e6 + 10;
// int n, m, k;
// int a[N];
#define int long long
const int mod = 998244353;
void solve() {
    int n, k;
    cin >> n >> k;
    // priority_queue<int> q;
    vector<int> a(n);
    // int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    // for (auto& i : a) {
    //     i = i % mod;
    // }
    int loc = n;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            loc = i;
            break;
        }
    }

    int mx = a[0] % mod;
    for (int i = 1; i < loc; i += (k - 1)) {
        if (i + k - 1 > loc) break;
        // int tmp = 1;
        for (int j = i; j < i + k - 1; j++) {
            mx = (mx * a[j]) % mod;
        }
        // cout << i << " " << tmp << endl;
        // if (tmp == 0) {
        //     break;
        // }
        // mx = mx * tmp % mod;
    }
    cout << mx << '\n';
    // vector<int> tmp;
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