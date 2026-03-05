#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n, m, k;
int a[N];
void solve() {
    cin >> n >> k;
    int mi = 1e18;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        mi = min(mi, a[i]);
    }
    vector<int> sum(n + 2);
    for (int i = n; i >= 1; i--) {
        sum[i] = sum[i + 1] + cnt[i];
    }
    for (int i = n; i >= 1; --i) {
        int s = cnt[i];
        if (2 * i <= n) s += cnt[2 * i];
        if (3 * i <= n) s += cnt[3 * i];
        int t4 = 0;
        if (4 * i <= n) t4 += sum[4 * i];
        if (n - t4 - s <= k) {
            cout << i << "\n";
            return;
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