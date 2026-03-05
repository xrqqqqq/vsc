#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

using i128 = __int128_t;
auto& operator>>(istream& it, __int128_t& j) {
    string val;
    it >> val;
    reverse(val.begin(), val.end());
    __int128_t ans = 0;
    bool f = 0;
    char c = val.back();
    val.pop_back();
    for (; c < '0' || c > '9'; c = val.back(), val.pop_back()) {
        if (c == '-') {
            f = 1;
        }
    }
    for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back()) {
        ans = ans * 10 + c - '0';
    }
    j = f ? -ans : ans;
    return it;
}
auto& operator<<(ostream& os, const __int128_t& j) {
    string ans;
    function<void(__int128_t)> write = [&](__int128_t x) {
        if (x < 0) ans += '-', x = -x;
        if (x > 9) write(x / 10);
        ans += x % 10 + '0';
    };
    write(j);
    return os << ans;
}
#define int i128
int n, m, k;
int a[N];
int b[N];
int ask(int x) {
    cout << x << endl;
    int t;
    cin >> t;
    return t - 2 * x;
}
void solve() {
    int mx = (1 << 30) - 1;
    int jmx = 0;
    for (int i = 0; i < 30; ++i) {
        if (i % 2) {
            jmx += (1 << i);
        }
    }
    int omx = mx - jmx;
    int t1 = ask(jmx);
    int t2 = ask(omx);
    int x = 0, y = 0;
    int sum = t1 + t2;
    t1 = -(t1 - sum);
    t2 = -(t2 - sum);
    for (int i = 0; i < 30; ++i) {
        int t11 = (t1 >> i) & 1;
        int t22 = (t2 >> i) & 1;
        // cout<<t11<<" "<<t22<<endl;
        if (t11) {
            if (i % 2) {
                x += (1 << i);
            } else {
                y += (1 << (i - 1));
                x += (1 << (i - 1));
            }
        }
        if (t22) {
            if (i % 2 == 0) {
                y += (1 << i);
            } else {
                y += (1 << (i - 1));
                x += (1 << (i - 1));
            }
        }
        // cout<<x<<" "<<y<<endl;
    }
    // cout<<t1<<" "<<t2<<endl;
    // cout<<x<<" "<<y<<endl;
    cout << "!" << endl;
    int m;
    cin >> m;
    cout << (m) << endl;
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