#include <bits/stdc++.h>
using namespace std;
#define int long long
#define a2 array<int, 2>
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int b[N];
int p;
int dfs(int u, int ned, int v) {
    if (u < 0) {
        return ned % p == 1;
    }
    if (v) {
        int tem = 0;
        tem = (ned + (1ll << (u + 1)) - 2) / p + 1;
        int te = 0;
        if (ned == 0)
            te = 0;
        else {
            te = (ned - 1) / p + 1;
        }
        return tem - te + (ned % p == 1 ? 1 : 0);
    }
    int ans = 0;
    int tem = 0;
    if (a[u]) {
        tem = (1ll << u);
    }
    if (b[u]) {
        ans += dfs(u - 1, ned + tem, 1);
        ans += dfs(u - 1, ned + (tem ^ (1ll << u)), 0);
    } else {
        ans += dfs(u - 1, ned + tem, 0);
    }
    return ans;
}
void solve() {
    cin >> p >> m;
    int n = p - 1;
    int len1 = 0;
    while (n) {
        a[len1++] = n % 2;
        n >>= 1;
    }
    n = m;
    int len2 = 0;
    while (n) {
        b[len2++] = n % 2;
        n >>= 1;
    }
    int ned = 0;
    if (len2 < len1) {
        for (int i = len2; i < len1; ++i) {
            if (a[i]) {
                ned += (1ll << i);
            }
        }
    }
    cout << dfs(len2 - 1, ned, 0) << "\n";
    for(int i = 0; i <= len1; ++i) a[i] = 0;
    for(int i = 0; i <= len2 ;++i) b[i] = 0;
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