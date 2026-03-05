#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 10;
int n, m, k;
int a[N];
int b[N];
int p[N];
int cn = 0;
int cp = 0;
int t[N];
int sum;
int ask(int *a, int n) {
    cout << "? " << n;
    for (int i = 1; i <= n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
}
int ans[N];
int c[N];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        if (i <= m) {
            cout << "OK\n";
        } else {
            cout << "Too Many Requests\n";
        }
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