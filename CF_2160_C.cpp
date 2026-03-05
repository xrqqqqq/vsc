#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
int a[N];
int b[N];
void solve() {
    cin >> n;
    int len = 0;
    while (n) {
        a[++len] = n % 2;
        n /= 2;
    }
    int mx = 0;
    for (int i = 1; i <= len; ++i) {
        int r = len;
        int l = len - i + 1;
        if (l < 1) break;
        bool v = 1;
        while (r >= l) {
            if (a[r] != a[l]) {
                v = 0;
                break;
            }
            r--;
            l++;
        }
        if (v) {
            mx = i;
        }
    }
    int l = len - mx;
    if (l <= 0) {
        if (len % 2 == 1) {
            if (a[(len + 1) / 2] == 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    for (int i = l; i >= 1; --i) {
        if (a[i] == 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = len + 1; i <= len + l; ++i) {
        a[i] = 0;
    }
    len += l;
    if ((len) % 2 == 1) {
        if (a[(len + 1) / 2] == 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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