
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m, k;
string s;
bool f(int l, int r) {
    int len = r - l + 1;
    for (int i = l; i <= len / 2 + l - 1; ++i) {
        if (s[i] != s[r + l - i]) {
            return 0;
        }
    }
    return 1;
}
void se(int l, int r) {
    for (int i = l; i <= r; ++i) cout << s[i];
    cout << " ";
}
void solve() {
    cin >> s;
    n = s.size();
    // s = " " + s;
    // n = s.size();
    if (f(0, n - 1) == 0) {
        cout << "YES\n";
        cout << 1 << "\n";
        cout << s << "\n";
    } else {
        int t = 0;
        while (t < n && s[0] == s[t]) t++;
        if (t >= n) {
            cout << "NO\n";
        } else {
            
            if (!f(t + 1, n - 1)) {
                cout << "YES\n";
                cout << 2 << "\n";
                se(0, t);
                se(t + 1, n - 1);
                cout << "\n";
            } else {
                if (t == 1 || t == (n + 1) / 2 - 1) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    cout << 2 << "\n";
                    se(0, t + 1);
                    se(t + 2, n - 1);
                    cout << "\n";
                }
            }
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